import image

border = "#FF0000"
square = "#0000FF"
width, height = 240, 60
midx, midy = width // 2, height // 2
image = image.Image(width, height, "square_eye.img")
for x in range(width):
    for y in range(height):
        if x < 5 or x >= width - 5 or y < 5 or y >= height-5:
            image[x, y] = border
        elif midx - 20 < x < midx + 20 and midy - 20 < y < midy + 20:
            image[x, y] = square

image.save()
image.export('square_eye.xpm')