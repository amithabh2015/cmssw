#ifndef EDM_EDPRODUCERWORKER_INCLUDED
#define EDM_EDPRODUCERWORKER_INCLUDED

/*----------------------------------------------------------------------
  
ProducerWorker: The EDProducer as the schedule sees it.  The job of
this object is to call the producer, collect up the results, and
feed them into the event.
According to our current definition, a single producer can only
appear in one worker.

$Id: ProducerWorker.h,v 1.2 2005/06/23 05:23:10 wmtan Exp $

----------------------------------------------------------------------*/

#include <memory>

#include "boost/shared_ptr.hpp"

#include "FWCore/CoreFramework/interface/CoreFrameworkfwd.h"
#include "FWCore/CoreFramework/src/Worker.h"
#include "FWCore/CoreFramework/interface/ModuleDescription.h"

namespace edm
{

  class ProducerWorker : public Worker
  {
  public:
    ProducerWorker(std::auto_ptr<EDProducer>, const ModuleDescription&);
    virtual ~ProducerWorker();

  private:
    virtual bool doWork(EventPrincipal& e, EventSetup const& c);

    ModuleDescription md_;
    boost::shared_ptr<EDProducer> producer_;
  };

  template <> 
  struct WorkerType<EDProducer>
  {
    typedef EDProducer ModuleType;
    typedef ProducerWorker worker_type;
  };

}

#endif // EDM_EDPRODUCERWORKER_INCLUDED
