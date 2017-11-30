module Warmup exposing (..)
import Regex exposing (..)

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

powers: Int -> Int -> List Int
powers base maxValue = [0]

sumOfCubesOfOdds: List Int -> Int
sumOfCubesOfOdds intList = 0

daysBetween: String -> String -> Int
daysBetween start end = 0
