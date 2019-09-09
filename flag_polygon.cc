// https://stackoverflow.com/questions/217578/how-can-i-determine-whether-a-2d-point-is-within-a-polygon

//
// I run a semi-infinite ray horizontally (increasing x, fixed y) out from the test point, 
// and count how many edges it crosses. 
// At each crossing, 
// the ray switches between inside and outside. 
// This is called the Jordan curve theorem.
//
// The variable c is switching from 0 to 1 and 1 to 0 each time the horizontal ray crosses any edge.
// So basically it 's keeping track of whether the number of edges crossed are even or odd. 
// 0 means even and 1 means odd.
//

bool Inside_Polygone(int nvert, float *vertx, float *verty, float testx, float testy)
{
  int i, j;
  bool c = false;
  for (i = 0, j = nvert-1; i < nvert; j = i++) {
    if ( ((verty[i]>testy) != (verty[j]>testy)) &&
     (testx < (vertx[j]-vertx[i]) * (testy-verty[i]) / (verty[j]-verty[i]) + vertx[i]) )
       c = !c;
  }
  return c;
}
