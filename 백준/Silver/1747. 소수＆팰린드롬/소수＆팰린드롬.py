def get_primary_num_eratos(N):
    nums = [True] * (N)
    
    for i in range(2, len(nums) // 2 + 1):
        if nums[i] == True:
            for j in range(i+i, N, i):
                nums[j] = False
    return [i for i in range(2, N) if nums[i] == True]


def is_palindrome(num):
    result = False
    if str(num) == str(num)[::-1]:
        result = True
        
    return result


def primary_num_and_palindrome(num, prime_numbers):
    answer = 0
    is_prime_palindrome = False
    
    for prime_number in prime_numbers:
        if prime_number >= num and is_palindrome(prime_number):
            answer = prime_number
            break
    if answer == 0:
        answer = 1003001
        
    return answer

if __name__ == "__main__":
    number = int(input())
    
    prime_numbers = get_primary_num_eratos(1000001)
    
    print(primary_num_and_palindrome(number, prime_numbers))