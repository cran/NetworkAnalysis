\name{NetworkAnalysis-internal}

%%% Small functions, serving as building blocks.
\alias{vec2sym2}
\alias{belong}
\alias{transposing}
\alias{cost2adj}
\alias{naObj}
\alias{top.metric}
\alias{vector.thres}
\alias{pos2ind}

%%% Functions to be documented in the future.
\alias{fdr}
\alias{giant.cpnt}
\alias{ge.ind}
\alias{le.ind}
\alias{edge.update}
\alias{na.DistanceOrdering}
\alias{na.IndirectPaths}
\alias{number.cpnts}

%%% C++ only functions (often used for verifications.)
\alias{cxx.ge}
\alias{cxx.order}
\alias{cxx.Hg}
\alias{cxx.cost}
\alias{cxx.cost.int}

%%% Old functions, which are being depricated.
\alias{cutoff.int.metric}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\title{Internal NetworkAnalysis Functions}
\description{Internal NetworkAnalysis functions}
\details{
These are not to be called by the user (or in some cases are just
waiting for proper documentation to be written).}
\keyword{internal}