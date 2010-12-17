/*

Recursive Clustering Algorithm, C Pseudocode 2008.


How do we define clusters? It’s an interesting problem. Given a series of point in Euclidean space, how do we group entities into clusters with some degree of confidence. Clearly it is not as trivial as one might first suppose since we have no relationship between entities in space. Often we will want to group entities based on location and proximity. How best to do it? One way is recursion. The following pseudo code highlights how given locations in x,y,z space one can generate a cluster map based on proximity.

Often in the biological science we want to group molecules together, for example to look at aggregation of molecules or atoms. One example I have used the code for is self assembly, where the aim is to group clustered molecules together. The clustering algorithm labels clusters and their child molecules, these clusters may then be statistically analysed.

1. Begins with an arbitrary molecule.
2. Subsequently determine its nearest neighbours that are deemed to be on the same cluster.
3. Each one of these nearest neighbours is then used as the starting point for the next nearest neighbour search until the recursive tree is exhausted and no more molecules are found.
4. Once the molecules in an aggregate have been exhausted, a linear search finds a molecule
that is not part of any preexisting aggregate and the procedure repeats.

The nearest neighbour search only includes molecules within a radius limited to close neighbours (these are our rules and can be tuned accordingly). The algorithm is robust against a wide range of nearest neighbour distances. The below incarnation in C has been cut down from my Data structures to make it simpler to follow. Clusters are stored as arrays - with no more clusters than the number of particles - ClusterList. Adding to a cluster is done with AddtoMaster which ensures that the molecules have not been added before to previous clusters. When I get the chance I’ll rewrite it in Python and provide some simple input files.


###################################################################################################################################################################

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.


*/


void RecursiveSearch(int Mastermol, int Currentmol, int
ClusterList[])
{

TargetBeadParent1 = Currentmol;
    for (molIndex2=0;molIndex2<MoleculeTotal;molIndex2++)
     {
        TargetBeadParent2 = molIndex2;
        //# get SelectedBeadTarget2
        if (sqrt(RadiusSq) <= (R_x))
        {
              success = AddToMaster(ClusterList,TargetBeadParent2,Mastermol);
              if (success)
              {
                    molsAdded+=1;
                    RecursiveSearch(Mastermol,TargetBeadParent2,ClusterList);
              }   
        }
       }
}

bool AddToMaster(int ClusterList[], int
ExternalBeadParent, int Master)
{

int InsertionPoint = ClusterList[Master][0][1];
    bool clash = false;
    int test, Agg;
    for (Agg=0;Agg<molTotal;Agg++)
    {
        for (test=0;test<molTotal;test++)

{
              if (ClusterList[Agg][test][0] == ExternalBeadParent)
              {
                clash = true;
              }
        }
    }

if (!clash)
    {
          ClusterList[Master][InsertionPoint][0] = ExternalBeadParent;
          ClusterList[Master][0][1] +=1;
          return(true);

}else
    {
          return(false);

}
}
