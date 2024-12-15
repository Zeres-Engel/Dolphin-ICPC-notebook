import subprocess, random, os
NAME = "problem"
TL = 5
NTEST = 100
main_script = f"{NAME}" if os.path.exists(f"{NAME}") else f"{NAME}.py"
bf_script = f"{NAME}_bf" if os.path.exists(f"{NAME}_bf") else f"{NAME}_bf.py"
main_cmd = [f"./{main_script}"] if not main_script.endswith(".py") else ["python3", main_script]
bf_cmd = [f"./{bf_script}"] if not bf_script.endswith(".py") else ["python3", bf_script]
def generate_test():
    input = input
    return input
for i in range(1, NTEST + 1):
    test_input = generate_test()
    with open(f"{NAME}.inp", "w") as f:
        f.write(test_input)
    subprocess.run(main_cmd, stdin=open(f"{NAME}.inp"), stdout=open(f"{NAME}.out", "w"), timeout=TL)
    subprocess.run(bf_cmd, stdin=open(f"{NAME}.inp"), stdout=open(f"{NAME}.ans", "w"), timeout=TL)
    out_main = open(f"{NAME}.out").read().strip()
    out_bf = open(f"{NAME}.ans").read().strip()
    if out_main != out_bf:
        print(f"Comparing files {NAME}.out and {NAME}.ans\n***** {main_script}:\n{out_main}\n***** {bf_script}:\n{out_bf}\n*****\n\nTest {i}: WRONG!")
        break
    print(f"Test {i}: CORRECT!")
else:
    print("All test cases passed!")
