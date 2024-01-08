import os
import shutil

filenames = [filename for filename in os.listdir('.') if '.png' in filename]
filenames = sorted(filenames)
for i, filename in enumerate(filenames):
    name, index = filename.split('_')
    shutil.move(filename, f"{name}_{i:05d}.png")
