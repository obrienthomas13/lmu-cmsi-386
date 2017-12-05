import Html exposing (Html, Attribute, body, div, input, text, h1)
import Html.Attributes exposing (style)
import Warmup exposing (daysBetween)

main =
  Html.beginnerProgram { model = model, view = view, update = update }


-- MODEL

type alias Model = Int

model : Model
model =
  0


-- UPDATE

type Msg = Reset

update : Msg -> Model -> Model
update msg model =
  case msg of
    Reset ->
      9

view : Model -> Html Msg
view model =
  body
  [ style
    [ ("text-align", "center")
      , ("font", "16px Arial")
      , ("background-color", "linen")
      , ("margin", "0")
    ]
  ]
  [
    h1Styled "Date Calculator"
  ]

h1Styled : String -> Html msg
h1Styled msg =
  h1
  [ style
    [ ("font", "bold 40px Avenir")
      , ("margin-top", "0")
      , ("padding", "5px")
      , ("background-color", "cyan")
    ]
  ]
  [ text msg ]
