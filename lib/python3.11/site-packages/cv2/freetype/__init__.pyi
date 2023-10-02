import cv2
import cv2.typing
import typing


# Classes
class FreeType2(cv2.Algorithm):
    # Functions
    def loadFontData(self, fontFileName: str, idx: int) -> None: ...

    def setSplitNumber(self, num: int) -> None: ...

    @typing.overload
    def putText(self, img: cv2.typing.MatLike, text: str, org: cv2.typing.Point, fontHeight: int, color: cv2.typing.Scalar, thickness: int, line_type: int, bottomLeftOrigin: bool) -> cv2.typing.MatLike: ...
    @typing.overload
    def putText(self, img: cv2.UMat, text: str, org: cv2.typing.Point, fontHeight: int, color: cv2.typing.Scalar, thickness: int, line_type: int, bottomLeftOrigin: bool) -> cv2.UMat: ...

    def getTextSize(self, text: str, fontHeight: int, thickness: int) -> tuple[cv2.typing.Size, int]: ...



# Functions
def createFreeType2() -> FreeType2: ...


