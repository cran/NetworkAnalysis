\name{adjacency.matrix}
\alias{adjacency.random}
\alias{adjacency.regular}
\alias{adjacency.unihub}
\title{Uniform draw of a random adjacency matrix.}
\description{
 These functions returns constrained adjacency matrices according to 
 different specifications. Each of these functions returns an adjacency
 matrix by default.}
\usage{
adjacency.random(Nv, Ne, graph = FALSE)
adjacency.regular(Nv, Ne, graph = FALSE)
adjacency.unihub(Nv, Ne, graph = FALSE)
}
\arguments{
  \item{Nv}{Number of vertices in the desired unweighted graph.}
  \item{Ne}{Number of edges in the desired unweighted graph.}
  \item{graph}{Logical: If true, function returns an unweighted igraph
    object (see igraph package)}
}
\details{
  adjacency.random uniformly draws a random adjacency matrix from the space of all
  unweighted graph with a specified number of vertices and edges.

  adjacency.regular returns a regular matrix of the minimal dimension.

  adjacency.unihub returns a graph with at least one hub. If
  \eqn{Nv>Ne}, then all edges will be incident to a single vertex. 
}
\value{
  \item{A}{An adjacency matrix of order \eqn{Nv*Nv}.}
}
\references{
  Ginestet, C.E. and Simmons, A. (In Press). Statistical Parametric Network Analysis of Functional
  Connectivity Dynamics during a Working Memory Task. Neuroimage.
}
\author{
   Cedric E Ginestet <c.ginestet05@gmail.com>
}
\seealso{igraph-package}
\examples{
### Random Net
naHeatmap(adjacency.random(10,10))

### Regular Net
naHeatmap(adjacency.regular(10,10))

### Unihub Net
naHeatmap(adjacency.unihub(10,10))
}
\keyword{uniform distribution}
\keyword{random graph}
