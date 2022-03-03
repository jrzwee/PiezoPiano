#########################################################
#
# Legend
#
#########################################################

legend = [
    ("Ground", "gnd"),
    ("Power", "pwr"),
    ("LED", "led"),
    ("Internal Pin", "internal"),
    ("SWD Pin", "swd"),
    ("Digital Pin", "digital"),
    ("Analog Pin", "analog"),
    ("Other Pin", "other"),
    ("Microcontroller's Port", "mu-port"),
    ("Default", "default"),
]

#########################################################
#
# Buttons: Bottom
#
#########################################################

buttons_left_bottom = [
    [
        ("D20", "digital"),
        ("PC6", "mu-port"),
    ],
    [
        ("D21", "digital"),
        ("PC7", "mu-port"),
    ],
    [
        ("D22", "digital"),
        ("A0", "analog"),
        ("PD0", "mu-port"),
    ],
    [
        ("D32", "digital"),
        ("A10", "analog"),
        ("PE2", "mu-port"),
    ],
]

buttons_right_bottom = [
    [
        ("D36", "digital"),
        ("PF2", "mu-port"),
    ],
    [
        ("D35", "digital"),
        ("PF1", "mu-port"),
    ],
    [
        ("D34", "digital"),
        ("PF0", "mu-port"),
    ],
    [
        ("D33", "digital"),
        ("A11", "analog"),
        ("PE3", "mu-port"),
    ],
]

#########################################################
#
# Piezos: Left-hand-side
#
#########################################################

piezo_01 = [
    [
        ("D9", "digital"),
        ("PB1", "mu-port"),
        ("LED", "led"),
    ],
]

piezo_02 = [
    [
        ("D8", "digital"),
        ("PB0", "mu-port"),
        ("LED", "led"),
    ],
]

piezo_03 = [
    [
        ("D7", "digital"),
        ("PA7", "mu-port"),
        ("LED", "led"),
    ],
]

piezo_04 = [
    [
        ("D6", "digital"),
        ("PA6", "mu-port"),
        ("LED", "led"),
    ],
]


#########################################################
#
# Piezos: Right-hand-side
#
#########################################################

piezo_05 = [
    [
        ("D5", "digital"),
        ("PA5", "mu-port"),
        ("LED", "led"),
    ],
]

piezo_06 = [
    [
        ("D4", "digital"),
        ("PA4", "mu-port"),
        ("LED", "led"),
    ],
]

piezo_07 = [
    [
        ("D1", "digital"),
        ("PA1", "mu-port"),
        ("LED", "led"),
    ],
]

piezo_08 = [
    [
        ("D0", "digital"),
        ("PA0", "mu-port"),
        ("LED", "led"),
    ],
]

#########################################################
#
# I2C: Right-hand-side
#
#########################################################

i2c_con = [
    [
        ("QWIIC", "default"),
    ],
    [
        ("QWIIC", "default"),
    ],
]

#########################################################
#
# Header: Left-hand-side
#
#########################################################

header_lhs_a = [
    [("+5", "pwr")],
    [("GND", "gnd")],
    [
        ("D18~", "digital"),
        ("PC4", "mu-port"),
    ],
    [
        ("D23", "digital"),
        ("A1", "analog"),
        ("PD0", "mu-port"),
    ],
        [
        ("D24", "digital"),
        ("A2", "analog"),
        ("PD1", "mu-port"),
    ],
        [
        ("D25", "digital"),
        ("A3", "analog"),
        ("PD2", "mu-port"),
    ],
]



#########################################################
#
# LED labels
#
#########################################################

led_txrx = [
    [
        ("TX RX LED", "led"),
    ],
]


led_power = [
    [   
        ("POWER", "led"),
    ],
]

led_ws = [
    [
        ("D10", "digital"),
        ("PB2", "mu-port"),
        ("WS2812B", "led"),
    ],
]

led_rgb = [
    [
        ("D39~", "digital"),
        ("A15", "analog"),
        ("PF5", "mu-port"),
        ("RED", "led"),
    ],
        [
        ("D38~", "digital"),
        ("A14", "analog"),
        ("PF4", "mu-port"),
        ("BLUE", "led"),
    ],
        [
        ("D37", "digital"),
        ("A13", "analog"),
        ("PF3", "mu-port"),
        ("GREEN", "led"),
    ],
]

#########################################################
#
# Text blocks
#
#########################################################

title_1 = [
    '<tspan class="h1">PiezoPiano</tspan>',
    '<tspan class="h1">v1.3</tspan>',
]
para_2 = [
    '<tspan class="p">Pinout diagram created with <tspan class="italic">pinout (v0.0.10)</tspan></tspan>',
    '<tspan class="p">A Python package for creating pinout diagrams.</tspan>',
    '<tspan class="p"><tspan class="strong"><a href="https://pinout.readthedocs.io">pinout.readthedocs.io</a></tspan></tspan>',
]
para_1 = [
    #'<tspan class="p">NOTE: This is not official documentation.</tspan>',
    #'<tspan class="p">Diagram aesthetics from Arduino docs.</tspan>',
    #'<tspan class="p"><tspan class="strong"><a href="https://www.arduino.cc/">https://www.arduino.cc/</a></tspan></tspan>',
]