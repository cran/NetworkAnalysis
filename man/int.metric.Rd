\name{cost.int.metric}
\alias{cost.int.metric}
\title{Integration of topological metrics for weighted networks.}
\description{
  Most topological metrics are not well-defined for weighted
  networks/graphs. These two functions integrate such topological
  metrics with respect to the wiring cost of the corresponding weighted graph.
  Only global efficiency (ge) and local efficiency (le) are currently
  covered by this function. See details.
}
\usage{
cost.int.metric(R,
                bounds = c(0,1),
                Tmc = 100,
                metric = "ge",
                method = "mc",
                verbose = FALSE,
                samples = FALSE)
}
\arguments{
  \item{R}{Weighted similarity matrix subtending the weighted graph of interest.}
  \item{bounds}{Bounds of integration. Set to \eqn{[0,1]}, by default.}
  \item{Tmc}{Numeric: Number of Monte Carlo iteration, if method is
  "mc". Set to 100 by default (which is low).}
  \item{metric}{Character: Metric with respect to which the integration is conducted.}
  \item{method}{Character: Method to be used when conducting
  integration. This accept "mc" or "exhaustive". For large graphs, the
  exhaustive method can be very time consumming. See details.}
  \item{verbose}{Logical: If true, update about the Monte Carlo
  iterations will be printed.}
  \item{samples}{Logical: If true and method is "mc", the function
  returns the entire set of Monte Carlo samples. (This option is only
  valid for cost.int.metric.)}
}
\details{
  Currently, these functions only accept weighted matrices, as opposed
  to weighted graph objects from the igraph package. Subsequent updates
  of this package will make this possible.

  These functions can currently be used to compute both the cost-integrated global and
  local efficiencies (ge and le, respectively) of a weighted network.

  The choice of integration method is important. By default, integration
  is conducted using Monte Carlo simulation over 100 samples. We
  recommend that the user increases this to 1000 samples for most
  purposes. The 'exhaustive' method computes all the possible
  \eqn{Nv*(Nv-1)/2} costs of a weighted graphs obtained after
  conducting all thresholding. For large graphs, this method will be
  extremelly time-consuming, and is not recommended. 
  When choosing Monte Carlo integration, we also obtain an estimate of
  the variability of the integral, i.e. the Monte Carlo standard error.

  The similarity matrix (e.g. correlation matrix) should be standardized
  using the metric.standardization function prior to proceed with the
  cost.int.metric and cutoff.int.metric functions. See
  metric.standardization for details.
}
\value{
  \item{Vector}{With the default options, this function returns a
     vector of two values including the Monte Carlo estimate of the
     integral and the Monte Carlo standard error of that estimate.}
  \item{Samples}{If samples is TRUE, the function returns a matrix of
     values for the topological metrics of the thresholded graphs in the first
     column, wih the corresponding costs for each of these values in the
     second column.}
}
\author{
  Cedric E Ginestet <c.ginestet05@gmail.com>
}
\references{
  Ginestet, C.E. and Simmons, A. (2011). Statistical Parametric Network Analysis of Functional
  Connectivity Dynamics during a Working Memory Task. Neuroimage, 5(2), 688--704. 
}
\examples{

## Generate a simple weighted graph (subtended by a covariance matrix)
R <- cov(cbind(rnorm(100),rnorm(100),rnorm(100),rnorm(100),rnorm(100),rnorm(100)))
print(R); naHeatmap(R)

## IMPORTANT: One should standardize the metric before proceeding to integration!
R <- metric.standardization(R)
naHeatmap(R)

## Compute the cost-integrated global (ge) and local efficiencies (le) of R.
print(cost.int.metric(R,metric="ge"))
print(cost.int.metric(R,metric="le"))

## Alternatively, these quantities can be computed using the 'exhaustive' method. 
print(cost.int.metric(R,metric="ge",method="exhaustive"))
print(cost.int.metric(R,metric="le",method="exhaustive"))

}
\keyword{Cost-integration}
\keyword{metric.standardization}
