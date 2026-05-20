// 独自計算ライブラリ
#include "mymath.h"

// radian→degree
float DegToRad(float deg) {
	return deg * static_cast<float>(PI) / 180.0f;		// 角度をdegreeからradianに変換
}

// degree→radian
float RadToDeg(float rad) {
	return rad * 180.0f / static_cast<float>(PI);		// 角度をradianからdegreeに変換
}

// 当たり判定用。2つのboxが当たったかを判定
// 当たっていたら1, 当たっていなかったら0を返す
int IsHitBox(
	int x1, int y1, int w1, int h1,		// ひとつめのbox 左上(x,y), 大きさw,h
	int x2, int y2, int w2, int h2		// ふたつめのbox 左上(x,y), 大きさw,h
) {
	if (x1 < x2 + w2 && x2 < x1 + w1		// x方向の判定
		&& y1 < y2 + h2 && y2 < y1 + h1		// y方向の判定
        && w1 != 0 && h1 != 0           // box1の大きさがある
        && w2 != 0 && h2 != 0           // box2の大きさがある
        )
	{
		// 2つのboxは当たっている
		return 1;
	}

	// 2つのboxは当たっていない
	return 0;
}

int IsHitBox(MYRECT a, MYRECT b)
{
    //当たり判定を返す
    return IsHitBox(a.x, a.y, a.w, a.h, b.x, b.y, b.w, b.h);
}


// 当たり判定用。2つの円が当たったかを判定
// 当たっていたら1, 当たっていなかったら0を返す
int IsHitCircle(
	int x1, int y1, int r1,		// ひとつめのcircle 中心(x,y), 半径r
	int x2, int y2, int r2		// ふたつめのcircle 中心(x,y), 半径r
) 
{
	int dx = x1 - x2;
	int dy = y1 - y2;
	int radius = r1 + r2;

    return radius * radius > dx * dx + dy * dy;
}

int IsHitCircle(MYCIRCLE a, MYCIRCLE b)
{
    return IsHitCircle((int)a.x, (int)a.y, (int)a.r, (int)b.x, (int)b.y, (int)b.r);
}

int IsHitCircleBox(MYCIRCLE circle, MYRECT rect)
{
    //円中心から見て最も近い矩形点を探す
    float nearestX = Clamp((float)(rect.x + rect.w), circle.x, (float)rect.x);
    float nearestY = Clamp((float)(rect.y + rect.h), circle.y, (float)rect.y);
    float dx = circle.x - nearestX;
    float dy = circle.y - nearestY;
    float distanceSq = dx * dx + dy * dy;
    float radiusSq = circle.r * circle.r;
    return distanceSq <= radiusSq;
}



#define TwoPI   (PI * 2.0f)
#define PIOver2 (PI / 2.0f)

// イージング
float EasingLinear(float cnt, float start, float end, float frames) {
    return (end - start) * cnt / frames + start;
}
float EasingInQuad(float cnt, float start, float end, float frames) {
    cnt /= frames;
    return (end - start) * cnt * cnt + start;
}
float EasingOutQuad(float cnt, float start, float end, float frames) {
    cnt /= frames;
    return -(end - start) * cnt * (cnt - 2) + start;
}
float EasingInOutQuad(float cnt, float start, float end, float frames) {
    cnt /= frames / 2.0f;
    if (cnt < 1) {
        return (end - start) / 2.0f * cnt * cnt + start;
    }
    cnt--;
    return -(end - start) / 2.0f * (cnt * (cnt - 2.0f) - 1.0f) + start;
}
float EasingInCubic(float cnt, float start, float end, float frames) {
    cnt /= frames;
    return (end - start) * cnt * cnt * cnt + start;
}
float EasingOutCubic(float cnt, float start, float end, float frames) {
    cnt /= frames;
    cnt--;
    return (end - start) * (cnt * cnt * cnt + 1) + start;
}
float EasingInOutCubic(float cnt, float start, float end, float frames) {
    cnt /= frames / 2.0f;
    if (cnt < 1.0f) {
        return (end - start) / 2.0f * cnt * cnt * cnt + start;
    }
    cnt -= 2.0f;
    return (end - start) / 2.0f * (cnt * cnt * cnt + 2) + start;
}
float EasingInQuart(float cnt, float start, float end, float frames) {
    cnt /= frames;
    return (end - start) * cnt * cnt * cnt * cnt + start;
}
float EasingOutQuart(float cnt, float start, float end, float frames) {
    cnt /= frames;
    cnt--;
    return -(end - start) * (cnt * cnt * cnt * cnt - 1) + start;
}
float EasingInOutQuart(float cnt, float start, float end, float frames) {
    cnt /= frames / 2.0f;
    if (cnt < 1.0f) {
        return (end - start) / 2.0f * cnt * cnt * cnt * cnt + start;
    }
    cnt -= 2.0f;
    return -(end - start) / 2.0f * (cnt * cnt * cnt * cnt - 2) + start;
}
float EasingInQuint(float cnt, float start, float end, float frames) {
    cnt /= frames;
    return (end - start) * cnt * cnt * cnt * cnt * cnt + start;
}
float EasingOutQuint(float cnt, float start, float end, float frames) {
    cnt /= frames;
    cnt--;
    return (end - start) * (cnt * cnt * cnt * cnt * cnt + 1) + start;
}
float EasingInOutQuint(float cnt, float start, float end, float frames) {
    cnt /= frames / 2.0f;
    if (cnt < 1.0f) {
        return (end - start) / 2.0f * cnt * cnt * cnt * cnt * cnt + start;
    }
    cnt -= 2.0f;
    return (end - start) / 2.0f * (cnt * cnt * cnt * cnt * cnt + 2.0f) + start;
}
float EasingInSine(float cnt, float start, float end, float frames) {
    return -(end - start) * static_cast<float>(cos(cnt / frames * (PIOver2))) + end + start;
}
float EasingOutSine(float cnt, float start, float end, float frames) {
    return (end - start) * static_cast<float>(sin(cnt / frames * PIOver2)) + start;
}
float EasingInOutSine(float cnt, float start, float end, float frames) {
    return -(end - start) / 2.0f * (static_cast<float>(cos(PI * cnt / frames)) - 1.0f) + start;
}
float EasingInExpo(float cnt, float start, float end, float frames) {
    return (end - start) * static_cast<float>(pow(2.0f, 10.0f * (cnt / frames - 1.0f))) + start;
}
float EasingOutExpo(float cnt, float start, float end, float frames) {
    return (end - start) * static_cast<float>((-pow(2.0f, -10.0f * cnt / frames) + 1.0f)) + start;
}
float EasingInOutExpo(float cnt, float start, float end, float frames) {
    cnt /= frames / 2.0f;
    if (cnt < 1) {
        return (end - start) / 2.0f * static_cast<float>(pow(2.0, 10.0f * (cnt - 1.0f))) + start;
    }
    cnt--;
    return (end - start) / 2.0f * (static_cast<float>(-pow(2.0, -10.0f * cnt)) + 2.0f) + start;
}
float EasingInCirc(float cnt, float start, float end, float frames) {
    cnt /= frames;
    return -(end - start) * static_cast<float>((sqrt(1.0f - cnt * cnt) - 1.0f)) + start;
}
float EasingOutCirc(float cnt, float start, float end, float frames) {
    cnt /= frames;
    cnt--;
    return (end - start) * static_cast<float>(sqrt(1.0f - cnt * cnt)) + start;
}
float EasingInOutCirc(float cnt, float start, float end, float frames) {
    cnt /= frames / 2.0f;
    if (cnt < 1.0f) {
        return -(end - start) / 2.0f * static_cast<float>((sqrt(1 - cnt * cnt) - 1.0f)) + start;
    }
    cnt -= 2.0f;
    return (end - start) / 2.0f * static_cast<float>((sqrt(1 - cnt * cnt) + 1.0f)) + start;
}

// 範囲内を返す
float Clamp(float min_n, float max_n, float n) {
    if (n <= min_n) { return min_n; }
    if (n >= max_n) { return max_n; }
    return n;
}
