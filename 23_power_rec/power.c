unsigned power(unsigned x, unsigned y)
{
  unsigned ans =x;
  if (x==0 && y == 0)
    return 1;
  else if(x==0 && y>0)
    return 0;
  else if(x>0 && y==0)
    return 1;
  else
  {
    y--;
    
    return ans*power(x, y);
    
  }
}
