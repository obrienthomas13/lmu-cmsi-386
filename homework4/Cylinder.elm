module Cylinder exposing (..)

type alias Cylinder = { radius: Float, height: Float }
-- type alias Cylinder = { radius: Maybe Float, height: Maybe Float }
type Msg = ChangeRadius Float | ChangeHeight Float

-- new : Float -> Float -> Cylinder
-- new r h = { radius = r || 1.0, height = h || 1.0 }

new : Cylinder
new =
  { radius = 1.0, height = 1.0 }

-- update : Msg -> Cylinder -> Cylinder
-- update msg model =
--     case msg of
--         ChangeRadius r -> { model | radius = r }
--         ChangeHeight h -> { model | height = h }

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
