import cv2

img = cv2.imread("home.jpg")
gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

sift = cv2.SIFT_create()
keypoints: list[cv2.KeyPoint] = sift.detect(gray_img, None)

print("keypoints[0]:")
print("\t class_id: \t", keypoints[0].class_id)
print("\t angle: \t", keypoints[0].angle)
print("\t octave: \t", keypoints[0].octave)
print("\t pt: \t\t", keypoints[0].pt)
print("\t size: \t\t", keypoints[0].size)
print("\t response: \t", keypoints[0].response)

# calculating descriptors
keypoints, descriptors = sift.compute(gray_img, keypoints)

print("descriptors[0]: ", descriptors[0])

# annotated_img = cv2.drawKeypoints(gray_img, keypoints, img)
annotated_img = cv2.drawKeypoints(
    gray_img, keypoints, img, flags=cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS
)

cv2.imwrite("sift_keypoints.jpg", annotated_img)
