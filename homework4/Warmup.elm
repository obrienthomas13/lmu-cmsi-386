module Warmup exposing (..)
import Regex exposing (replace, regex)
import Arithmetic exposing (..)
import Date exposing(fromString)
import Date.Extra.Duration exposing (diffDays)

change: Int -> Result String (Int, Int, Int, Int)
change cents =
  if (<) cents 0 then
    Err "amount cannot be negative"
  else
    let
      quarters = (//) cents 25
      quartersValue = (-) cents ((*) quarters 25)
      dimes = (//) (quartersValue) 10
      nickels = (//) ((-) quartersValue ((*) dimes 10)) 5
    in
      Ok (quarters, dimes, nickels, (%) cents 5)

stripQuotes: String -> String
stripQuotes =
  Regex.replace Regex.All (Regex.regex "[\'\"]") (\_ -> "")

powers: Int -> Int -> Result String (List Int)
powers base max =
  if (<) base 0 then
    Err "negative base"
  else
    Ok <| List.map (\c -> (^) base c) (List.range 0 <| floor <| logBase (toFloat <| base) (toFloat <| max))

sumOfCubesOfOdds: List Int -> Int
sumOfCubesOfOdds intList =
  List.foldr (+) 0 <| List.map (\x -> (^) x 3) <| List.filter isOdd intList

daysBetween: String -> String -> Result String Int
daysBetween start end =
  let
    startDate = Date.fromString start
    endDate = Date.fromString end
  in
    case (startDate, endDate) of
      (Ok startDate, Ok endDate) ->
        Ok <| Date.Extra.Duration.diffDays endDate startDate
      _ ->
        Err "Bad data"
-- DISGUSTING
-- daysBetween: String -> String -> Result String Int
-- daysBetween start end =
--   let
--     startDate = Date.fromString start
--     endDate = Date.fromString end
--   in
--     case startDate of
--       Ok start ->
--         case endDate of
--           Ok end ->
--             Ok <| Date.Extra.Duration.diffDays end start
--           Err msg ->
--             Err "Bad data"
--       Err msg ->
--         Err "Bad data"
