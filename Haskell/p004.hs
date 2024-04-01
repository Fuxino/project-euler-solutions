-- A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
--
-- Find the largest palindrome made from the product of two 3-digit numbers.

isPalindrome :: Integer -> Bool
isPalindrome n = show n == (reverse $ show n)

maxPalindrome :: Integer
maxPalindrome =
    maximum $ filter isPalindrome [ x * y | x <- [100..999], y <- [100..999] ]

main = do
    let result = maxPalindrome
    putStrLn $ "Project Euler, Problem 4\n"
        ++ "Answer: " ++ (show result)
