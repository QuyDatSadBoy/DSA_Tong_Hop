def matrix_square(matrix):
    a, b, c, d = matrix
    return [a*a + b*c, a*b + b*d, c*a + d*c, c*b + d*d]

# Hàm tính lũy thừa bậc n của ma trận [[2, 3], [1, 2]]


def matrix_power(matrix, n):
    result = [1, 0, 0, 1]  # Ma trận đơn vị
    while n > 0:
        if n % 2 == 1:
            result = matrix_square(result)
        matrix = matrix_square(matrix)
        n //= 2
    return result

# Hàm lấy 2 chữ số đầu tiên trước dấu phẩy của số thực


def get_first_two_digits(number):
    integer_part = int(number)
    return (integer_part // 10) % 10, integer_part % 10


# Đọc số lượng bộ test
T = int(input().strip())

for _ in range(T):
    n = int(input().strip())

    # Ma trận mô tả biểu thức (2 + √3)^n
    matrix = [2, 3, 1, 2]

    # Tính lũy thừa bậc n của ma trận
    result_matrix = matrix_power(matrix, n)

    # Lấy giá trị trong ma trận và tính số thực
    value = result_matrix[0] * (2 + 3 ** 0.5) + \
        result_matrix[1] * (2 - 3 ** 0.5)

    # Lấy 2 chữ số đầu tiên trước dấu phẩy
    first_digit, second_digit = get_first_two_digits(value)

    # In kết quả với định dạng 2 chữ số
    print(f"{first_digit:02}{second_digit:02}")
