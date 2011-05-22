#!/bin/bash
foldername=$1"_png"
filename=$1.avi
mkdir $foldername
ffmpeg -i $filename $foldername/frame_%d.png
