from pinout.core import Group, Image, Raw, Rect
from pinout.components.layout import Diagram, Panel
from pinout.components import pinlabel, legend, leaderline
from pinout.components.text import TextBlock
import sys

# Import data and custom function
# Slightly inelegant method to amend module search path
#sys.path.append("..")
import piezopiano_data as data
from common.preprocessor import pinlabel_preprocessor as prep

# Create a new digram
diagram = Diagram(1200, 675, tag="piezopiano")

# Add a stylesheet and some custom patterns
diagram.add_stylesheet("./common/styles.css", True)

# Load some svg markup to be used as patterns
# The Raw class allows arbitary code to be inserted
# into the diagram.
with open("./common/patterns.xml") as f:
    patterns = f.read()
diagram.add_def(Raw(patterns))

# Construct a layout and add some backgrounds
diagram.add(Rect(x=0, y=0, width=1200, height=675, tag="diagram__bg"))
group_main = diagram.add(Group(2, 2, tag="panel panel--main"))
group_main.add(Rect(x=0, y=0, width=1196, height=548, tag="panel__bg"))

# Keeping elements in a group allows for easier measuring and moving
# Create a group for the main pinout graphic
pinout_graphic = group_main.add(Group(600, 10, tag="pinout-graphic"))

group_notes = diagram.add(Group(2, 552, tag="panel panel--notes"))
group_notes.add(Rect(x=0, y=0, width=1196, height=121, tag="panel__bg"))
group_notes.add(
    legend.Legend(data.legend, max_height=112, x=10, y=5, inset=(0, 0, 0, 0))
)
group_notes.add(TextBlock(data.title_1, 22, x=580, y=30))
group_notes.add(TextBlock(data.para_1, 17, x=580, y=74))
group_notes.add(TextBlock(data.para_2, 17, x=900, y=74))



# IMPORTANT NOTE
#   Use the hardware_15 (15% scaled image of hardware) 
#   for measurements in pixels
# END

# Add a hardware image
# Note its coordinates are relative to the group it is within

startpoint_x = -374 / 2
startpoint_y = 10

pinout_graphic.add(
    Image(
        "hardware.png",
        width=374,
        height=421,
        x=startpoint_x,
        y=startpoint_y,
        embed=True,
    )
)

# Piezos 1 left
pinout_graphic.add(
    pinlabel.PinLabelGroup(
        x=startpoint_x + 47,
        y=startpoint_y + 115,
        pin_pitch=(0, 0),
        scale=(-1, 1),
        label_start=(90+30, 96 - 115 + 23.35),
        label_pitch=(0, 23.35),
        labels=prep(data.piezo_01),
        tag="pinheader",
    )
)

# Piezos 2 left
pinout_graphic.add(
    pinlabel.PinLabelGroup(
        x=startpoint_x + 76,
        y=startpoint_y + 161,
        pin_pitch=(0, 0),
        scale=(-1, 1),
        label_start=(90+76-17, 96 - 161 + (2*23.35)),
        label_pitch=(0, 23.35),
        labels=prep(data.piezo_02),
        tag="pinheader",
    )
)

# Piezos 3 left
pinout_graphic.add(
    pinlabel.PinLabelGroup(
        x=startpoint_x + 100,
        y=startpoint_y + 96,
        pin_pitch=(0, 0),
        scale=(-1, 1),
        label_start=(90+100-17, 0),
        label_pitch=(0, 23.35),
        labels=prep(data.piezo_03),
        tag="pinheader",
    )
)

# Piezos 4 left
pinout_graphic.add(
    pinlabel.PinLabelGroup(
        x=startpoint_x + 128,
        y=startpoint_y + 199,
        pin_pitch=(0, 0),
        scale=(-1, 1),
        label_start=(90+128-17, 96 - 199 + (3 * 23.35)),
        label_pitch=(0, 23.35),
        labels=prep(data.piezo_04),
        tag="pinheader",
    )
)

# Piezos 5 right
pinout_graphic.add(
    pinlabel.PinLabelGroup(
        x=startpoint_x + 128,
        y=startpoint_y + 143,
        pin_pitch=(0, 0),
        scale=(1, -1),
        label_start=(90+228, - 96 + 143 - (2*23.35)),
        label_pitch=(0, 23.35),
        labels=prep(data.piezo_05),
        tag="pinheader",
    )
)

# Piezos 6 right
pinout_graphic.add(
    pinlabel.PinLabelGroup(
        x=startpoint_x + 158,
        y=startpoint_y + 96,
        pin_pitch=(0, 0),
        scale=(1, -1),
        label_start=(90+198, 0),
        label_pitch=(0, 23.35),
        labels=prep(data.piezo_06),
        tag="pinheader",
    )
)

# Piezos 7 right
pinout_graphic.add(
    pinlabel.PinLabelGroup(
        x=startpoint_x + 181,
        y=startpoint_y + 161,
        pin_pitch=(0, 0),
        scale=(1, -1),
        label_start=(90+175, - 96 + 161 - (3*23.35)),
        label_pitch=(0, 23.35),
        labels=prep(data.piezo_07),
        tag="pinheader",
    )
)

# Piezos 8 right
pinout_graphic.add(
    pinlabel.PinLabelGroup(
        x=startpoint_x + 211,
        y=startpoint_y + 115,
        pin_pitch=(0, 0),
        scale=(1, -1),
        label_start=(90+145, - 96 + 115 - 23.35),
        label_pitch=(0, 23.35),
        labels=prep(data.piezo_08),
        tag="pinheader",
    )
)

# I2C QWICC right
pinout_graphic.add(
    pinlabel.PinLabelGroup(
        x=startpoint_x + 250,
        y=startpoint_y + 154,
        pin_pitch=(0, 38),
        scale=(1, 1),
        label_start=(90+105, 70),
        label_pitch=(0, 23.35),
        labels=prep(data.i2c_con),
        tag="pinheader",
    )
)

# LEDs pwr
pinout_graphic.add(
    pinlabel.PinLabelGroup(
        x=startpoint_x + 83,
        y=startpoint_y + 22,
        pin_pitch=(0, 0),
        scale=(-1, 1),
        label_start=(90+64, 0),
        label_pitch=(0, 23.35),
        labels=prep(data.led_power),
        tag="pinheader",
    )
)

# LED WS2812B
pinout_graphic.add(
    pinlabel.PinLabelGroup(
        x=startpoint_x + 20,
        y=startpoint_y + 256,
        pin_pitch=(0, 0),
        scale=(-1, 1),
        label_start=(90+2, -10),
        label_pitch=(0, 23.35),
        labels=prep(data.led_ws),
        tag="pinheader",
    )
)

# LED RXTX
pinout_graphic.add(
    pinlabel.PinLabelGroup(
        x=startpoint_x + 150,
        y=startpoint_y + 62,
        pin_pitch=(0, 0),
        scale=(1, -1),
        label_start=(90+64, 20),
        label_pitch=(0, 23.35),
        labels=prep(data.led_txrx),
        #leaderline=leaderline.Curved(direction="vh"),
        tag="pinheader",
    )
)

# LED RGB
pinout_graphic.add(
    pinlabel.PinLabelGroup(
        x=startpoint_x + 237,
        y=startpoint_y + 342,
        pin_pitch=(0, 0),
        scale=(1, 1),
        label_start=(90+118, 0),
        label_pitch=(0, 23.35),
        labels=prep(data.led_rgb),
        #leaderline=leaderline.Curved(direction="vh"),
        tag="pinheader",
    )
)

# Bottom buttons
pinout_graphic.add(
    pinlabel.PinLabelGroup(
        x=startpoint_x + 19,
        y=startpoint_y + 404,
        pin_pitch=(48, 0),
        scale=(-1, 1),
        label_start=(90, 30),
        label_pitch=(0, 23.35),
        labels=prep(data.buttons_left_bottom),
        leaderline=leaderline.Curved(direction="vh"),
        tag="pinheader",
    )
)

pinout_graphic.add(
    pinlabel.PinLabelGroup(
        x=startpoint_x + 355,
        y=startpoint_y + 404,
        pin_pitch=(-48, 0),
        scale=(1, 1),
        label_start=(90, 30),
        label_pitch=(0, 23.35),
        labels=prep(data.buttons_right_bottom),
        leaderline=leaderline.Curved(direction="vh"),
        tag="pinheader",
    )
)


# Left hand side pin header
pinout_graphic.add(
    pinlabel.PinLabelGroup(
        x=startpoint_x + 8,
        y=startpoint_y + 306,
        pin_pitch=(0, 10.5),
        label_start=(90-11, -30),
        label_pitch=(0, 23.35),
        scale=(-1, 1),
        labels=prep(data.header_lhs_a),
        tag="pinheader",
    )
)