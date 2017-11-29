module Warmup exposing (..)
import Regex exposing (..)

change: Int -> (Int, Int, Int, Int)
change s = (0, 0, 0, 0)

stripQuotes: String -> String
stripQuotes =
  Regex.replace Regex.All (Regex.regex "[\'\"]") (\_ -> "")

powers: Int -> Int -> List Int
powers base maxValue = [0]

sumOfCubesOfOdds: List Int -> Int
sumOfCubesOfOdds intList = 0

daysBetween: String -> String -> Int
daysBetween start end = 0
