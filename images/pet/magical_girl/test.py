import os
import shutil

filenames = [filename for filename in os.listdir('.') if '.png' in filename]
for filename in filenames:
    name, index = filename.split('_')
    shutil.move(filename, f"{name}_0{index}")
