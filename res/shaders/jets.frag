uniform sampler2D currentTexture;
uniform float time;

#define M_PI 3.1415926535897932384626433832795
// procedural noise from IQ
vec2 hash( vec2 p )
{
	p = vec2( dot(p,vec2(127.1,311.7)),
			 dot(p,vec2(269.5,183.3)) );
	return -1.0 + 2.0*fract(sin(p)*43758.5453123);
}

float noise( in vec2 p )
{
	const float K1 = 0.366025404; // (sqrt(3)-1)/2;
	const float K2 = 0.211324865; // (3-sqrt(3))/6;

	vec2 i = floor( p + (p.x+p.y)*K1 );

	vec2 a = p - i + (i.x+i.y)*K2;
	vec2 o = (a.x>a.y) ? vec2(1.0,0.0) : vec2(0.0,1.0);
	vec2 b = a - o + K2;
	vec2 c = a - 1.0 + 2.0*K2;

	vec3 h = max( 0.5-vec3(dot(a,a), dot(b,b), dot(c,c) ), 0.0 );

	vec3 n = h*h*h*h*vec3( dot(a,hash(i+0.0)), dot(b,hash(i+o)), dot(c,hash(i+1.0)));

	return dot( n, vec3(70.0) );
}

float fbm(vec2 uv)
{
	float f;
	mat2 m = mat2( 1.6,  1.2, -1.2,  1.6 );
	f  = 0.5000*noise( uv ); uv = m*uv;
	f += 0.2500*noise( uv ); uv = m*uv;
	f += 0.1250*noise( uv ); uv = m*uv;
	f += 0.0625*noise( uv ); uv = m*uv;
	f = 0.5 + 0.5*f;
	return f;
}

vec4 getColor(float n, float index)
{
    //c = clamp(max(n, index), 0., 1.);
    index = min(index, clamp(n, 0., 1.));
    return vec4(0.25 * index*index*index, 0.5*index*index, index, index);
}

vec4 CheckRect(vec2 coord, vec2 p, vec2 n, float a, float b){
    vec2 shift = coord - p;

    float len = length(shift);
    float cosv = dot(shift / len, n);
    float cosv2 = cosv * cosv;
    float sinv2 = 1. - cosv2;
    float need_len = sqrt(b * b * cosv2 + a * a * sinv2);
    float angle = acos(cosv);

    if (angle * 2 < M_PI && len <= need_len)
    {
        vec2 q = shift;
        q.x /= a;
        q.y /= b;

        float index = 1. - len / need_len;
        float nois = fbm(q - vec2(0, 6.5*time));

        return getColor(nois, index);
    }

    return vec4(0.);
}

void main() {
    vec2 coord = gl_TexCoord[0].xy;
    vec4 pixel_color = texture2D(currentTexture, coord);

    if (pixel_color.a == 1.)
        gl_FragColor = pixel_color;
    else
    {
        vec4 jets[3];
        jets[0] = CheckRect(coord, vec2(.5, .75), vec2(0.0, 1.0), .25, .3);
        jets[1] = CheckRect(coord, vec2(.1, .55), vec2(0.0, 1.0), 0.05, .3);
        jets[2] = CheckRect(coord, vec2(.9, .55), vec2(0.0, 1.0), 0.05, .3);

        vec4 accum;
        for (int i = 0; i < 3; i++)
        {
            accum += jets[i];
        }
        if (accum .a == 0.)
            gl_FragColor = pixel_color;
        else
            gl_FragColor = accum; //mix(jet1, jet2, jet3, 0.33, 0.33, 0.33);
    }
}
