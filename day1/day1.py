input_file = open('real_input.txt', 'r')
data = input_file.readlines()

values = []
for line in data:
    values.append(line.strip())

sums = []
larger_sums = 0
previous_sum = 0
for i in range(0, len(values)):
    if i > len(values) - 1 or i + 1 > len(values) - 1 or i + 2 > len(values) - 1:
        break
    s = int(values[i]) + int(values[i+1]) + int(values[i+2])
    print(f"{values[i]} + {values[i+1]} + {values[i+2]} = {s}")

    if previous_sum == 0:
        previous_sum = s
        continue
    elif s > previous_sum:
        larger_sums += 1
    previous_sum = s


print(larger_sums)
