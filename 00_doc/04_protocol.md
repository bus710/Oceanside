[Back to main](../README.md#server)


# Protocol

Odroid C2 and Oceanside board are connected over serial (ttyS1 and uart1, respectively).  
  
In each side it is easy to read/write serial packets by accessing the interfaces but as these require various data exchange via the interface so that a protocol is suggested below.

Basically these use 115200 buad rate and each command consists of 39 bytes.

- 2 preambles
- 2 commands
- 2 packet IDs
- 1 type & length
- 32 payloads
- 1 checksum

Up to 295 commands can be sent per 1 second (11520 / 39 = 295).  
However, it is better to avoid full throughput but 80% might be good. (295 * 0.8 = 236 commands/second)

### Preable

Each byte is 0xAA so that a packet receiver (either Odroid or Oceanside) can easily find where to start reading by checking 2 bytes of 0xAA. 

### Command

The first byte is major command and it cartegorizes the next byte as minor command.

#### Major Command

| Index | Major Num  | Name |
| :------: | :------: | ------ | 
| 1 | 0 | System Information | 
| 2 | 1 | Hardware Configuration | 
| 3 | 10 | Application Configration | 
| 4 | 20 | Communication Configuration | 
| 5 | 30 | Sensor Data | 
| 6 | 40 | Motor Configuration | 
| ... | ... | ... | 
| n | 255 | Heart Beat | 

#### Minor Command

The MSB of minor command is an indicator of reading/writing so that bit 6 ~ 0 can be used to distinguish command categories.

| Index | Major Num | Name | Minor Num | Type | Name |
| :------: | :------: | ------ | :------: | :------: | ------ |
| 1 | 0 | System Information | 0x00 | R | Project Name | 
| 2 | 0 | "                 | 0x80 | W (N/A) | Project Name |
| 3 | 0 | System Information | 0x01 | R | Project Version | 
| 4 | 0 | "                 | 0x81 | W (N/A) | Project Version |
| 5 | 0 | System Information | 0x02 | R | Hardware Name | 
| 6 | 0 | "                 | 0x82 | W (N/A) | Hardware Version |
| 7 | 0 | System Information | 0x03 | R | MCU Name | 
| 8 | 0 | "                 | 0x83 | W (N/A) | MCU Name |
| 9 | 0 | System Information | 0x04 | R | Firmware Version | 
| 10 | 0 | "                 | 0x84 | W (N/A) | Firmware Version |
| n | 255 | Heart Beat | 0xff | N | |

### Packet ID

This ID can be used the order of each command to check if there is any missing command. Command recovery can be developed in the future.

### Type & Length

Type and Length are included in 1 byte.
  
Type is the MSB. 
- When it is 1, payload should be taken case as ascii string. 
- When it is 0, payload should be taken case as integers.
  
Length tells to receiver how many bytes are worth in payloads of 32 bytes.

### Payload

This is the actual data.  
Contents can be vary based on commands.


# Examples

### When Odroid wants to read Oceanside's MCU name

Since MCU name is a minor command and included under major command of System Information, the commands are 0x00 and 0x03 respectively.  
Also, Odroid needs to read that information so that the MSB of the minor command should be 0 (if it wants to write, it should be 1. That is meaningless though).
In case of reading, type, length, and payload don't matter so that let these leave as 0x00 (However, in case of writing, the fields should be filled).
  
The command's content based on above criteria is:
| Index | Name | Contents |
| :---: | --- | --- |
| 0 | Preamble 0 | 0xAA |
| 1 | Preamble 1 | 0xAA |
| 2 | Command 0 | 0x00 |
| 3 | Command 1 | 0x03 |
| 4 | Packet ID 0 | Lower layer takes care |
| 5 | Packet ID 1 | Lower layer takes care |
| 6 | Type & Length | 0x00 |
| 7~37 | Payload | 0x00 |
| 38 | Checksum | Lower layer takes care (Xor CRC of index 0~37). |

### When Oceanside is asked about its MCU name

Let's say above command is successfully decoded by Oceanside.  
Now the firmware should return the relevant data, "STM32F446Rx".
MSB of minor command doesn't matter but other field should be kept to show what the original request was for returned payload (Major: 0x00, Minor: 0x03).
Although Odroid won't read more than 32 bytes from the commands, Length might be helpful to decode payload.

The command's content based on above criteria is:
| Index | Name | Contents |
| :---: | --- | --- |
| 0 | Preamble 0 | 0xAA |
| 1 | Preamble 1 | 0xAA |
| 2 | Command 0 | 0x00 |
| 3 | Command 1 | 0x03 |
| 4 | Packet ID 0 | Lower layer takes care |
| 5 | Packet ID 1 | Lower layer takes care |
| 6 | Type & Length | 0x8B (128 + 11 = 139) |
| 7~17 | Payload 0~10 | 'STM32F446Rx' |
| 18~37 | Payload 11~31 | 0x00 |
| 38 | Checksum | Lower layer takes care (Xor CRC of index 0~37). |
