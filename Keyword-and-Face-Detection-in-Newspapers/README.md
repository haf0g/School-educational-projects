# Keyword and Face Detection in Newspapers

This project involves processing a ZIP file of images containing newspaper pages to detect keywords and faces. The script allows searching for specific keywords in the images and generating contact sheets of faces found on pages containing those keywords.

## Description

The project processes a ZIP file containing images of newspaper pages. It uses Python libraries to search for occurrences of keywords and detect faces in the images. The detected faces are then displayed in contact sheets along with the corresponding keyword.

## Features

- Searches for keywords in newspaper images
- Detects faces in images using OpenCV
- Performs optical character recognition (OCR) using Tesseract
- Generates contact sheets of faces related to specific keywords

## Technologies Used

- Python
- OpenCV
- Tesseract OCR
- PIL (Python Imaging Library)
- ZIP file processing

## Usage

1. Make sure you have Python installed on your system.
2. Download or clone this repository.
3. Place the ZIP file containing newspaper images in the same directory as the script.
4. Update the script with the correct path to the Tesseract executable if necessary.
5. Run the script: python keyword_face_detection.py

## Example Output

- The script processes a small ZIP file for the keyword "Christopher" and displays the resulting image with faces.
- It also processes a larger ZIP file for the keyword "Mark" and displays the resulting image.

## Project Structure

- `keyword_face_detection.py`: Python script for keyword and face detection.
- `haarcascade_frontalface_default.xml`: XML file for face detection cascade.
- `consolas_font.ttf`: Font file for text display.
- `small_img.zip`: Small ZIP file containing newspaper images for testing.
- `images.zip`: Larger ZIP file containing newspaper images.

## License

This project is licensed under the [MIT License](LICENSE).

