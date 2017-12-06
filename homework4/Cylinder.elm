module Cylinder exposing (..)

type alias Cylinder = { radius: Float, height: Float }

new : Cylinder
new =
  { radius = 1.0, height = 1.0 }

widen : Float -> Cylinder -> Cylinder
widen factor object =
  { radius = .radius object * factor, height = .height object }

stretch : Float -> Cylinder -> Cylinder
stretch factor object =
  { radius = .radius object, height = .height object  * factor }

volume : Cylinder -> Float
volume object =
  pi * .radius object * .radius object * .height object

surfaceArea : Cylinder -> Float
surfaceArea object =
  pi * .radius object * .height object * 2 + (2 * pi * .radius object * .radius object)
