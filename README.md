# palmslave_qmk
palmslave keymap setting in QMK

```
# setup
cd qmk_firmware/keyboards/takashicompany/
ln -s ~/palmslave palmslave
# compile/flash
# right
qmk flash -kb takashicompany/palmslave -km pasokata -bl avrdude-split-right
# left
qmk flash -kb takashicompany/palmslave -km pasokata -bl avrdude-split-left
```
