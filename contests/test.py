def min_cost_to_make_elements_equal(test_cases):
    results = []
    for n, array in test_cases:
        frequency = {}
        for num in array:
            if num in frequency:
                frequency[num] += 1
            else:
                frequency[num] = 1

        # Determine the most frequent element
        target = max(frequency, key=frequency.get)
        
        # Calculate the minimum cost to convert all elements to the target
        total_cost = 0
        i = 0
        while i < n:
            if array[i] != target:
                j = i
                while j < n and array[j] != target:
                    j += 1
                length_of_segment = j - i
                total_cost += length_of_segment * target
                i = j
            else:
                i += 1
        
        results.append(total_cost)
    return results

# Read input
t = int(input())
test_cases = []
for _ in range(t):
    n = int(input())
    array = list(map(int, input().split()))
    test_cases.append((n, array))

# Compute and print results
results = min_cost_to_make_elements_equal(test_cases)
for result in results:
    print(result)
