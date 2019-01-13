texture = TextureBox.new("starship1.png")
weap1 = WeaponBox.new(0.25, VectorBox.new(0, 0), VectorBox.new(0, 0))
weap2 = WeaponBox.new(0.25, VectorBox.new(0, 0), VectorBox.new(0, 0))
speed = SpeedBox.new(20, 20, 20)


addBox("first", CruiserBox.new(texture, weap1, weap2, speed))