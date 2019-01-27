texture = TextureBox.new("cruiser01.png")
laser_texture = TextureBox.new("laserCruiser01.png")

bullet01 = BulletBox.new(laser_texture, 100, 500)
weap1 = WeaponBox.new(bullet01, 0.25, VectorBox.new(-32, 0), VectorBox.new(0, -120))
weap2 = WeaponBox.new(bullet01, 0.25, VectorBox.new(32, 0), VectorBox.new(0, -120))
speed = SpeedBox.new(300, 170, 290)
addBox("first", StarshipBox.new(texture, speed, 1000, weap1, weap2))

-- enemy
core = TextureBox.new("core.png")
core_speed = SpeedBox.new(100, 100, 100)
plasmaBall = BulletBox.new(TextureBox.new("plasmaBall.png"), 100, 200)
plasmaBallWeapon = WeaponBox.new(plasmaBall, 5.0, VectorBox.new(0, 0), VectorBox.new(0, 0))
addBox("scout1", StarshipBox.new(core, core_speed, 1000, plasmaBallWeapon))