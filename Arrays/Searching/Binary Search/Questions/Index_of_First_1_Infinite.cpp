/*
    Index of first one in infinite sorted array

    000000001111111......


    For an infinite array take low = 0  high =1

    apply First Occuerence B.S and increase high = high*2 till key<arr[high] as key is bounded by low and high
    and start = prev end
*/

