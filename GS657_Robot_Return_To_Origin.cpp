class Solution {
public:
  bool judgeCircle(string moves) {
    int x = 0, y = 0;
    if(moves.size() == 0) return true;

    for(char direction : moves){
      pair<int,int> cord;
      switch(direction){
      case 'R':
	cord = make_pair(1,0);
	break;
      case 'L':
	cord= make_pair(-1,0);
	break;
      case 'U':
	cord = make_pair(0, 1);
	break;
      case 'D':
	cord = make_pair(0, -1);
	break;
      default:
	return false;
      }
      x += cord.first;
      y += cord.second;
    }
    return (x==0&&y==0);
  }
};
