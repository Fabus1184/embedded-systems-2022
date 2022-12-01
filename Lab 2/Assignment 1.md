# Assignment 1

1)
```
Start-Bit + Address-Byte + ACK + User-Byte + ACK + Stop-Bit
 = 20 Bit 
=> 20 Bit / (4 * 10⁵ Hz) = 5 * 10⁻⁵ s = 50µs
```

2)
| Method    | Description                                                                                                                                                   |
| --------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `Init()`  | Basic device initialization. Method is called during system initialization and sets device in a ‘safe’ state.                                                 |
| `Open()`  | Before using the I/O device it has to be opened. Opening the device, first, initializes the device for later usage, and second, marks the device as ‘in use’. |
| `Read()`  | Reads data from the device.                                                                                                                                   |
| `Write()` | Writes data to the device.                                                                                                                                    |
| `Close()` | Set device in ‘safe’ state and mark device as ‘not in use’.                                                                                                   |

3) This is used to amplify the signal to a higher voltage leve.

4) Voltage(n) = n / (2 ^ 12 - 1) * V_ref

5) 
   - arithmetic mean = sum m / n
   - variance = sum (m - mean)² / n
   - standard deviation = sqrt variance
   