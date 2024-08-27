import subprocess
import time

command = input("primegen | primesieve: ")

def measure(n):
  start_time = time.time()
  if (command == "primegen"):
    subprocess.run(['./primegen/primes', '1', str(n)], capture_output=True, text=True)
  else:
    subprocess.run(['primesieve', str(n)], capture_output=True, text=True)
  end_time = time.time()
  return end_time - start_time


max_digits = 11
arr = []

for i in range(1, max_digits + 1):
  arr.append(measure(10**i))

all_values = ""
for i in range(len(arr)):
  all_values += str(arr[i]) + ","

  formatted = "{:.6f}".format(arr[i])
  print(f"{i+1} digits: {formatted}s")

with open("./out/values.csv", "w") as file:
    file.write(all_values[:-1])