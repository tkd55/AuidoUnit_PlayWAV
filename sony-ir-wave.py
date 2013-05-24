
# -*- coding: utf-8 -*-
import wave
import struct

# Sony IR Protocol protocol

# command
# power	         1010100
# volume up      0100100
# volume down    1100100
# channel up     0000100
# channel down   1000100
# channel 1      0000000
# channel 2      1000000
# channel 3      0100000
# play           0101100
# pause          1001100
# open           0110100
# enter          1011110

command = '1011110'

# address
# TV              10000
# BlueRay         0101101001111

address = '0101101001111'

frequency = 40000

cycle = 1000000 / frequency # microsec
pulse_width = 600 # microsec
cip = pulse_width / cycle # number of cycles in a pulse

bit_type = 12 # 12bit
repeat = 3
repeat_duration = 45000 # microsec

# number of pulses [HIGH, LOW]
header = (4, 1) # high * 4 + low * 1
one = (2, 1) # high * 2 + low * 1
zero = (1, 1) # high * 1 + low * 1

# wave data
short_max = struct.pack('h', 32767)
short_min = struct.pack('h', -32768)
short_gnd = struct.pack('h', 0)

left_polar = (short_max, short_min)
right_polar = (short_min, short_max)
equator = (short_gnd, short_gnd)

high_pulse = ()
low_pulse = equator * cip

for i in range(cip) :
	high_pulse += left_polar if i%2 else right_polar

frames = ()

# IR header
frames += high_pulse * header[0]
frames += low_pulse * header[1]

# IR command and address
signal =  command + address
for i in signal :
	if i == '1':
		frames += high_pulse * one[0]
		frames += low_pulse * one[1]
	else:
		frames += high_pulse * zero[0]
		frames += low_pulse * zero[1]

# IR add tail to repeat
frames += equator * ((repeat_duration - len(frames) * cycle / 2) / cycle)

# repeat
frames = ''.join(frames * repeat)

# wave file
wavefile = wave.open("wavefile.wav", "w")
wavefile.setparams((2, 2, frequency, len(frames), "NONE", "not compressed"))
wavefile.writeframes(frames)
wavefile.close()
