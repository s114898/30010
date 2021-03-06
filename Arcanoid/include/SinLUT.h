// =====================================================================
//
//	Exported by Cearn's excellut v1.0
//	(comments, kudos, flames to daytshen@hotmail.com)
//
// =====================================================================

#ifndef SINLUT_H
#define SINLUT_H

// === LUT SIZES ===
#define SIN_SIZE 512



// === LUT DECLARATIONS ===
extern const signed short SIN[512];

signed short sin(int i);
signed short cos(int i);

void rotate(struct TVector *v, long deg);
void initVector(struct TVector *v, long a, long b);

#endif	// SINLUT_H
