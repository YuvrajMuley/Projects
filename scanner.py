#!/usr/bin/python3

import sys
import socket

# Check for correct arguments
if len(sys.argv) == 1:
    print(f"Usage: {sys.argv[0]} IP START(optional) END(optional)", file=sys.stderr)
    exit(1)

# Parse arguments
ip = sys.argv[1]
start = 1
end = 65535

if len(sys.argv) >= 3:
    start = int(sys.argv[2])
    if len(sys.argv) >= 4:
        end = int(sys.argv[3])

# Function to check port status
def check_port_status(port: int) -> bool:
    try:
        s = socket.socket()
        s.settimeout(1)
        s.connect((ip, port))
        s.close()
        return True
    except (ConnectionRefusedError, socket.timeout):
        return False

# Loop through the port range and check each port
for port in range(start, end + 1):
    response = check_port_status(port)
    if response:
        print(f"Open Port Found [{port}]")

