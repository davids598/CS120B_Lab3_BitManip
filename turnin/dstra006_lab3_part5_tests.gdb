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
test "PINB: 0x01, PIND: 0x30 => PORTB: 0x02"
# Set inputs
setPINB 0x01
setPIND 0x30
# Continue for several ticks
continue 2
# Set expect values
expectPORTB 0x02
# Check pass/fail
checkResult

# Add tests below
# Test 2
test "PINB: 0x00, PIND: 0x01 => PORTB: 0x00"
# Set inputs
setPINB 0x00
setPIND 0x01
# Continue for several ticks
continue 2
# Set expect values
expectPORTB 0x00
# Check pass/fail
checkResult

# test 3
test "PINB: 0x01, PIND: 0x33 => PORTB: 0x02"
# Set inputs
setPINB 0x01
setPIND 0x33
# Continue for several ticks
continue 2
# Set expect values
expectPORTB 0x02
# Check pass/fail
checkResult

# Test 4
test "PINB: 0x00, PIND: 0x3F => PORTB: 0x02"
# Set inputs
setPINB 0x00
setPIND 0x3F
# Continue for several ticks
continue 2
# Set expect values
expectPORTB 0x02
# Check pass/fail
checkResult

# Test 5
test "PINB: 0x01, PIND: 0x0A => PORTB: 0x04"
# Set inputs
setPINB 0x01
setPIND 0x0A
# Continue for several ticks
continue 2
# Set expect values
expectPORTB 0x04
# Check pass/fail
checkResult

# Test 6
test "PINB: 0x01, PIND: 0xFF => PORTB: 0x02"
# Set inputs
setPINB 0x01
setPIND 0xFF
# Continue for several ticks
continue 2
# Set expect values
expectPORTB 0x02
# Check pass/fail
checkResult
# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
