//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Register all services implementation.
//---------------------------------------------------------------------
#include "register_all_services.h"

#include <string>
#include <vector>

#include <server/core_service_registrar.h>
#include <server/session_repository.h>

#include "nidaqmx/nidaqmx_service_registrar.h"
#include "nidcpower/nidcpower_service_registrar.h"
#include "nidigitalpattern/nidigitalpattern_service_registrar.h"
#include "nidmm/nidmm_service_registrar.h"
#include "nifgen/nifgen_service_registrar.h"
#include "nirfmxinstr/nirfmxinstr_service_registrar.h"
#include "nirfmxspecan/nirfmxspecan_service_registrar.h"
#include "nirfsa/nirfsa_service_registrar.h"
#include "nirfsg/nirfsg_service_registrar.h"
#include "niscope/niscope_service_registrar.h"
#include "niswitch/niswitch_service_registrar.h"
#include "nisync/nisync_service_registrar.h"
#include "nitclk/nitclk_service_registrar.h"

namespace nidevice_grpc {

std::shared_ptr<void> register_all_services(
  grpc::ServerBuilder& server_builder,
  const nidevice_grpc::FeatureToggles& feature_toggles)
{
  auto service_vector = std::make_shared<std::vector<std::shared_ptr<void>>>();

  auto session_repository = std::make_shared<nidevice_grpc::SessionRepository>();
  auto core_service = nidevice_grpc::register_core_service(server_builder, session_repository);
  service_vector->insert(
    service_vector->end(), 
    {session_repository, core_service});

  auto task_handle_repository = std::make_shared<nidevice_grpc::SessionResourceRepository<TaskHandle>>(session_repository.get());
  auto vi_session_repository = std::make_shared<nidevice_grpc::SessionResourceRepository<ViSession>>(session_repository.get());
  auto ni_r_fmx_instr_handle_repository = std::make_shared<nidevice_grpc::SessionResourceRepository<niRFmxInstrHandle>>(session_repository.get());

  service_vector->push_back(
    nidaqmx_grpc::register_service(
      server_builder, 
      task_handle_repository,
      feature_toggles));
  service_vector->push_back(
    nidcpower_grpc::register_service(
      server_builder, 
      vi_session_repository,
      feature_toggles));
  service_vector->push_back(
    nidigitalpattern_grpc::register_service(
      server_builder, 
      vi_session_repository,
      feature_toggles));
  service_vector->push_back(
    nidmm_grpc::register_service(
      server_builder, 
      vi_session_repository,
      feature_toggles));
  service_vector->push_back(
    nifgen_grpc::register_service(
      server_builder, 
      vi_session_repository,
      feature_toggles));
  service_vector->push_back(
    nirfmxinstr_grpc::register_service(
      server_builder, 
      ni_r_fmx_instr_handle_repository,
      feature_toggles));
  service_vector->push_back(
    nirfmxspecan_grpc::register_service(
      server_builder, 
      ni_r_fmx_instr_handle_repository,
      feature_toggles));
  service_vector->push_back(
    nirfsa_grpc::register_service(
      server_builder, 
      vi_session_repository,
      feature_toggles));
  service_vector->push_back(
    nirfsg_grpc::register_service(
      server_builder, 
      vi_session_repository,
      feature_toggles));
  service_vector->push_back(
    niscope_grpc::register_service(
      server_builder, 
      vi_session_repository,
      feature_toggles));
  service_vector->push_back(
    niswitch_grpc::register_service(
      server_builder, 
      vi_session_repository,
      feature_toggles));
  service_vector->push_back(
    nisync_grpc::register_service(
      server_builder, 
      vi_session_repository,
      feature_toggles));
  service_vector->push_back(
    nitclk_grpc::register_service(
      server_builder, 
      vi_session_repository,
      feature_toggles));

  return service_vector;
}

} // nidevice_grpc
