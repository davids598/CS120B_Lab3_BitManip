# Test file for "Lab3_BitManip"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly,
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Test 1
test "PINA: 0x30, PINB: 0x03 => PORTC: 0x00"
# Set inputs
setPINA 0x30
setPINB 0x03
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x00
# Check pass/fail
checkResult

# Add tests below
# Test 2
test "PINA: 0x01, PINB: 0x00 => PORTC: 0x10"
# Set inputs
setPINA 0x01
setPINB 0x00
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x10
# Check pass/fail
checkResult

# test 3
test "PINA: 0x33, PINB: 0x03 => PORTC: 0x30"
# Set inputs
setPINA 0x33
setPINB 0x03
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x30
# Check pass/fail
checkResult

# Test 4
test "PINA: 0x3F, PINB: 0x03 => PORTC: 0xF0"
# Set inputs
setPINA 0x3F
setPINB 0x03
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0xF0
# Check pass/fail
checkResult

# Test 5
test "PINA: 0x7A, PINB: 0x07 => PORTC: 0xA0"
# Set inputs
setPINA 0x7A
setPINB 0x07
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0xA0
# Check pass/fail
checkResult

# Test 6
test "PINA: 0x2D, PINB: 0x02 => PORTC: 0xD0"
# Set inputs
setPINA 0x2D
setPINB 0x02
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0xD0
# Check pass/fail
checkResult
# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
