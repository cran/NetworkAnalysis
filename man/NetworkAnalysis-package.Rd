\name{NetworkAnalysis-package}
\alias{NetworkAnalysis-package}
\alias{NetworkAnalysis}
\docType{package}
\title{Statistical inference on populations of weighted or unweighted networks.}
\description{
Network analysis refers to the utilization of graph theory for the
analysis of a range of different types of connectivity data. The set of
objects contained in this package will be particularly useful for the
analysis of groups of networks in neuroimaging, where several
populations of subject-specific networks are available. Future versions
will include the derivation of SPNs (statistical parametric networks).}
\details{
\tabular{ll}{
Package: \tab NetworkAnalysis\cr
Type: \tab Package\cr
Version: \tab 0.3-1\cr
Date: \tab 2010-12-01\cr
License: \tab GPL (>= 2)\cr
LazyLoad: \tab yes\cr
}
The most important functions in the current version of this software is
cost.int.metric. This function permits to compute the cost-integrated version of
particular topological metrics for weighted graphs.

Throughout the manual pages for this package, the terms graphs and
networks are used interchangeably. Moreover, the adjacency or similarity
matrices are also sometimes used directly to refer to the unweighted and
weighted graphs that they subtend.

Visually, this package uses some of the plotting functionality of the
igraph package in order to obtain a graphical representation of the
graphs of interest.
}
\author{
Author and maintainer: Cedric E. Ginestet <cedric.ginestet@kcl.ac.uk>
}
\references{
  Ginestet, C.E. and Simmons, A. (2011). Statistical Parametric Network Analysis of Functional
  Connectivity Dynamics during a Working Memory Task. Neuroimage, 5(2), 688--704. 
}
\keyword{cost-integration}
\keyword{cutoff-integration}
\keyword{topological metric}
\examples{

#### Produce an adjacency matrix with a random topology.
A <- adjacency.random(10,15)
naHeatmap(A)

#### Cost-integrated 'global efficiency' of a simple weighted (correlation) matrix.
R <- cor(cbind(rnorm(100),rnorm(100),rnorm(100),rnorm(100),rnorm(100),rnorm(100)))
naHeatmap(R)
print(cost.int.metric(R)[1])

#### Compute its cutoff-integrated matrix
print(cutoff.int.metric(R)[1])

#### Using a real data set from an fMRI study, representing functional
#### connectivity between 90 brain regions. We here only consider a
#### subset of these regions. 
data(nback1)
W <- nback1[1:20,1:20]
naHeatmap(W)
W <- metric.standardization(W)
cost.int.metric(W)

}
