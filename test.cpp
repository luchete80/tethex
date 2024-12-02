#include "tethex.h"
#include "config.h"
#include <algorithm>
#include <fstream>
#include <cmath>

using namespace tethex;

void mesh_2d_1(std::string &input_file, std::string &output_file)
{
  input_file = "mesh_2d_1.msh";
  output_file = "mesh_2d_1_hex.msh";
  std::ofstream out(input_file.c_str());
  require(out, "File " + input_file + " cannot be opened!");
  out << "$MeshFormat\n2.2 0 8\n$EndMeshFormat\n$Nodes\n";
  out << "3\n";
  out << "1 0 0 0\n";
  out << "2 1 0 0\n";
  out << "3 0 1 0\n";
  out << "$EndNodes\n$Elements\n";
  out << "3\n";
  out << "1 2 2 11 0 1 2 3\n";
  out << "2 15 2 41 0 1\n";
  out << "3 15 2 42 0 3\n";
  out << "$EndElements\n";
  out.close();
}

#include <iostream>
using namespace std;

int main(){
  

//---------------------------------------------------------
//
// Tests 2D
//
//---------------------------------------------------------


  std::string input_file, output_file;
  mesh_2d_1(input_file, output_file);
  
  cout << "Reading file "<<input_file<<endl;
  Mesh mesh;
  try
  {
    mesh.read(input_file);
    cout << "mesh readed. "<<endl;
      cout << "Vertices: "<<mesh.get_n_vertices()<<endl;
        cout << "Edges: "<<mesh.get_n_edges()<<endl; 
        cout << "Lines: "<<mesh.get_n_lines()<<endl;
        cout << "Points: "<<mesh.get_n_points()<<endl;
        
  }
  catch (std::runtime_error &e)
  {
    std::cout << "\n=== EXCEPTION === \n";
    std::cout << e.what() << std::endl << std::endl;;
  }
  cout << "Converting mesh "<<endl;
  mesh.convert();
  cout << "Vertices: "<<mesh.get_n_vertices()<<endl;
  mesh.write(output_file);
  
  // vertices and mesh elements from the file
  std::vector<Point> vertices;
  vertices.push_back(Point(0, 0, 0));
  vertices.push_back(Point(1, 0, 0));
  vertices.push_back(Point(0, 1, 0));

  std::vector<Line> edges;
  edges.push_back(Line(0, 1, 11));
  edges.push_back(Line(0, 2, 11));
  edges.push_back(Line(1, 2, 11));

  std::vector<Line> lines;
  std::vector<Line> new_lines;

  std::vector<Triangle> triangles;
  triangles.push_back(Triangle(0, 1, 2, 11));
  triangles[0].set_edge(0, 0);
  triangles[0].set_edge(1, 1);
  triangles[0].set_edge(2, 2);
  
  

  /*
  std::vector<Quadrangle> quadrangles;
  quadrangles.push_back(Quadrangle(0, 3, 6, 4, 11));
  quadrangles.push_back(Quadrangle(1, 5, 6, 3, 11));
  quadrangles.push_back(Quadrangle(2, 4, 6, 5, 11));

  // new vertices created after conversion from triangles to quadrangles
  std::vector<Point> new_vertices;
  new_vertices.push_back(Point(1./2., 0, 0));
  new_vertices.push_back(Point(0, 1./2., 0));
  new_vertices.push_back(Point(1./2., 1./2., 0));
  new_vertices.push_back(Point(1./3., 1./3., 0));

  // physical points
  std::vector<PhysPoint> points;
  points.push_back(PhysPoint(0, 41));
  points.push_back(PhysPoint(2, 42));
  
  
  
  // once again for converted mesh
  new_vertices.clear(); // vertices already include new_vertices
  edges.clear(); // we don't generate edges for quadrangles
  lines.clear(); // there are no original lines
#if defined(DELETE_SIMPLICES)
  triangles.clear(); // there are no triangles anymore
#endif
*/

  
return 0;
}
