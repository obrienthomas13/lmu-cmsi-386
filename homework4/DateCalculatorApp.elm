import Html exposing (Html, Attribute, body, span, input, text, h1, p)
import Html.Attributes exposing (style, id, value, type_)
import Html.Events exposing (onInput)
import Warmup exposing (daysBetween)

main =
  Html.beginnerProgram { model = model, view = view, update = update }

-- MODEL

type alias Model =
  { from : String
  , to : String
  }

model : Model
model =
  { from = ""
  , to = ""
  }

-- UPDATE

type Msg = ChangeFrom String | ChangeTo String

update : Msg -> Model -> Model
update msg model =
  case msg of
    ChangeFrom fromDate ->
      { model | from = fromDate }
    ChangeTo toDate ->
      { model | to = toDate }

dateCalcMessage : String -> String -> String
dateCalcMessage fromDate toDate =
    case daysBetween fromDate toDate of
      Ok days -> toString days
      _ -> ""

-- VIEW

view : Model -> Html Msg
view model =
  bodyStylized
    [ h1Stylized "Date Calculator"
    , p []
      [ text "From "
      , inputStylized1 "from"
      ]
    , p []
      [ text "To "
      , inputStylized2 "to"
      ]
    , p []
      [ text "is "
      , spanStylized "output" (dateCalcMessage model.from model.to)
      , text " days."
      ]
  ]

spanStylized: String -> String -> Html msg
spanStylized idName msg =
  span
    [ id idName
    , style [ ("font-size", "28px") ]
    ] [ text msg ]

bodyStylized: List (Html msg) -> Html msg
bodyStylized htmlMsg =
  body
    [ style
      [ ("text-align", "center")
      , ("font", "16px Arial")
      , ("background-color", "linen")
      , ("margin", "0")
      ]
    ] htmlMsg

h1Stylized : String -> Html msg
h1Stylized msg =
  h1
    [ style
      [ ("font", "bold 40px Avenir")
      , ("margin-top", "0")
      , ("padding", "5px")
      , ("background-color", "cyan")
      ]
    ] [ text msg ]

inputStylized1 : String -> Html Msg
inputStylized1 idName =
  input
    [ style
      [ ("border", "2px solid grey")
      , ("margin-left", "8px")
      ]
      , id idName
      , type_ "date"
      , onInput ChangeFrom
    ] []

inputStylized2 : String -> Html Msg
inputStylized2 idName =
  input
    [ style
      [ ("border", "2px solid grey")
      , ("margin-left", "8px")
      ]
      , id idName
      , type_ "date"
      , onInput ChangeTo
    ] []
