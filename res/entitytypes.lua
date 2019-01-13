texture = TextureBox.new("starship1.png")
weap1 = WeaponBox.new(0.25, VectorBox.new(-10, 0), VectorBox.new(0, -21))
weap2 = WeaponBox.new(0.25, VectorBox.new(10, 0), VectorBox.new(0, -21))
speed = SpeedBox.new(190, 170, 140)


addBox("first", CruiserBox.new(texture, weap1, weap2, speed))