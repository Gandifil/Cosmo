laser_texture = TextureBox.new("laserCruiser01.png")
bullet01 = BulletBox.new(laser_texture, 100, 700)

--mothership
mtexture = TextureBox.new("mothership.png")
weap1 = WeaponBox.new(bullet01, 0.75, VectorBox.new(-32, -30), VectorBox.new(0, -120))
empty_speed = SpeedBox.new(0, 0, 0)
mothership = StarshipBox.new(mtexture, empty_speed, 1000)
addBox("second", CruiserBox.new(mothership, weap1, weap1))

--cruiser
texture = TextureBox.new("cruiser01.png")
weap1 = WeaponBox.new(bullet01, 0.25, VectorBox.new(-32, -30), VectorBox.new(0, -120))
weap2 = WeaponBox.new(bullet01, 0.25, VectorBox.new(32, -30), VectorBox.new(0, -120))
speed = SpeedBox.new(300, 170, 290)
cruiserStarship = StarshipBox.new(texture, speed, 1000)
addBox("first", CruiserBox.new(cruiserStarship, weap1, weap2))

-- enemy
-- core
core = TextureBox.new("core.png")
core_speed = SpeedBox.new(100, 100, 100)
plasmaBall = BulletBox.new(TextureBox.new("plasmaBall.png"), 100, 200)
plasmaBallWeapon = WeaponBox.new(plasmaBall, 5.0, VectorBox.new(0, 0), VectorBox.new(0, 0))
addBox("scout1", CruiserBox.new(StarshipBox.new(core, core_speed, 1000), plasmaBallWeapon, weap2))