#!/bin/bash
# Convert MP4 to GIF

#usage:
# chmod +x tools/convert-to-gif.sh
#./tools/convert-to-gif.sh donut.mp4

if [ -z "$1" ]; then
  echo "Usage: ./convert-to-gif.sh input.mp4 [output.gif] [fps]"
  echo "Example: ./convert-to-gif.sh myvideo.mp4 output.gif 30"
  exit 1
fi

INPUT="$1"
OUTPUT="${2:-${INPUT%.mp4}.gif}"
FPS="${3:-30}"

# Generate high-quality color palette
ffmpeg -i "$INPUT" -vf "fps=$FPS,scale=-1:-1:flags=lanczos,palettegen" -y palette.png

# Generate GIF using palette for better colors
ffmpeg -i "$INPUT" -i palette.png -filter_complex "fps=$FPS,scale=-1:-1:flags=lanczos[x];[x][1:v]paletteuse=dither=sierra2_4a" -y "$OUTPUT"

echo "Conversion complete! Output: $OUTPUT"
rm -f palette.png  # Clean up

# Alternative method
# if [ $# -lt 2 ]; then
#   echo "Usage: $0 input.mp4 output.gif"
#   exit 1
# fi

# ffmpeg -i "$1" -vf "fps=15,scale=480:-1:flags=lanczos" -c:v gif "$2"
# echo "GIF saved as $2"
