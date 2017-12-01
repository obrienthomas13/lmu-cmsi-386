module Warmup exposing (..)
import Regex exposing (..)
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
      Ok (quarters, dimes, nickels, cents % 5)

stripQuotes: String -> String
stripQuotes =
  Regex.replace Regex.All (Regex.regex "[\'\"]") (\_ -> "")

-- powers: Int -> Int -> Result String (List Int)
powers: Int -> Int -> List Int
powers base maxValue = [0]
  -- I don't know this question is wild
  -- if (<) base 0 then
  --   Err "negative base"
  -- else
  --   let
  --     p result base maxValue =
  --       if (<=) p (List.head <| List.reverse maxValue)
  --   in
  --     if
  --     Ok [0]

-- Toal's example...??
-- collatz n =
--   let
--     c count n =
--       if n == 1 then count
--       else c (count+1) (if n % 2 == 0 then n // 2 else 3 * n + 1)
--   in
--     c 0 n


sumOfCubesOfOdds: List Int -> Int
sumOfCubesOfOdds intList =
  List.foldr (+) 0 <| List.map (\x -> x^3) <| List.filter isOdd intList

daysBetween: String -> String -> Result String Int
daysBetween start end =
  let
    startDate = Date.fromString start
    endDate = Date.fromString end
  in
    case startDate of
      Ok start ->
        case endDate of
          Ok end ->
            Ok <| Date.Extra.Duration.diffDays end start
          Err msg ->
            Err "Bad data"
      Err msg ->
        Err "Bad data"
