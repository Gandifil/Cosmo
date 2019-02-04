
speed = Speed.new(300, 170, 290)
laser_texture = Texture("laserCruiser01.png")
bullet01 = Bullet.new(laser_texture, 100, 500)
texture1 = Texture("cruiser01.png")
core = Texture("core.png")
plasma = Texture("plasmaBall.png")

add("text01", texture1)
add("text02", laser_texture)
add("text03", core)
add("text04", plasma)

-- player cruiser
weap1 = Weapon.new(bullet01, 0.25, Vector.new(-32, 0), Vector.new(0, -120))
weap2 = Weapon.new(bullet01, 0.25, Vector.new(32, 0), Vector.new(0, -120))
add("first", Starship(texture1, speed, 1000, weap1, weap2))

-- enemy
core_speed = Speed.new(100, 100, 100)
plasmaBall = Bullet.new(plasma, 100, 200)
plasmaBallWeapon = Weapon.new(plasmaBall, 5.0, Vector.new(0, 0), Vector.new(0, 0))
add("scout1", Starship(core, core_speed, 1000, plasmaBallWeapon))