\name{NetworkAnalysis-package}
\alias{NetworkAnalysis-package}
\alias{NetworkAnalysis}
\docType{package}
\title{Statistical inference on populations of weighted or unweighted networks.}
\description{
        Network analysis is a recently adopted phrase, which reflects the growing utilization 
        of graph theory for the analysis of a range of different types of connectivity data. 
        The set of objects contained in this package will particularly useful for the analysis of 
	population of networks in neuroimaging, where subject-specific networks are available. 
        Future versions will include an SPN (statistical parametric network) object, which permits to 
        summarize one or several populations of networks.}
\details{
\tabular{ll}{
Package: \tab NetworkAnalysis\cr
Type: \tab Package\cr
Version: \tab 1.0\cr
Date: \tab 2010-12-01\cr
License: \tab GPL (>= 2)\cr
LazyLoad: \tab yes\cr
}
The most important functions in the current version of this software are
cost.int.metric and cutoff.int.metric. These two functions permit to
compute the cost-integrated and the cutoff-integrated versions of
particular topological metrics for weighted graphs.

Throughout the manual pages for this package, the terms graphs and
networks are used interchangeably. Moreover, the adjacency or similarity
matrices are also sometimes used directly to refer to the unweighted and
weighted graphs that they subtend. 
}
\author{
Author and maintainer: Cedric E. Ginestet <c.ginestet05@gmail.com>
}
\references{
  Ginestet, C.E. and Simmons, A. (In Press). Statistical Parametric Network Analysis of Functional
  Connectivity Dynamics during a Working Memory Task. Neuroimage.  
}
\keyword{cost-integration}
\keyword{cutoff-integration}
\keyword{topological metric}
\examples{

#### Produce a graph with a random topology.
A <- adjacency.random(10,15)
naHeatmap(A)

#### Cost-integrated matrix of a simple weighted (correlation) matrix.
R <- cor(cbind(rnorm(100),rnorm(100),rnorm(100),rnorm(100),rnorm(100),rnorm(100)))
print(R);
naHeatmap(R)
print(cost.int.metric(R)[1])

#### Compute its cutoff-integrated matrix
print(cutoff.int.metric(R)[1])

#### Using a real data set from an fMRI study, representing functional
#### connectivity between 90 brain regions. 
data(nback1)
naHeatmap(nback1)
R <- metric.standardization(nback1)
cost.int.metric(R)

}
