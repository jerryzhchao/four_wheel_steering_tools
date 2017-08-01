/*********************************************************************
 * Software License Agreement (CC BY-NC-SA 4.0 License)
 *
 *  Copyright (c) 2014, PAL Robotics, S.L.
 *  All rights reserved.
 *
 *  This work is licensed under the Creative Commons
 *  Attribution-NonCommercial-ShareAlike 4.0 International License.
 *
 *  To view a copy of this license, visit
 *  http://creativecommons.org/licenses/by-nc-sa/4.0/
 *  or send a letter to
 *  Creative Commons, 444 Castro Street, Suite 900,
 *  Mountain View, California, 94041, USA.
 *********************************************************************/

/*
 * @author Enrique Fernandez
 */

#ifndef CMD_MUX_DIAGNOSTICS_H
#define CMD_MUX_DIAGNOSTICS_H

#include <cmd_mux/cmd_mux_diagnostics_status.h>

#include <diagnostic_updater/diagnostic_updater.h>
#include <ros/ros.h>

#include <boost/shared_ptr.hpp>

namespace cmd_mux
{

class CmdMuxDiagnostics
{
  public:
    typedef CmdMuxDiagnosticsStatus status_type;

    static constexpr double MAIN_LOOP_TIME_MIN = 0.2; // [s]
    static constexpr double READING_AGE_MIN    = 3.0; // [s]

    CmdMuxDiagnostics();
    virtual ~CmdMuxDiagnostics();

    void diagnostics(diagnostic_updater::DiagnosticStatusWrapper& stat);

    void update();

    void updateStatus(const status_type::ConstPtr& status);

  private:

    /**
     * @brief Levels
     */
    enum
    {
      OK    = diagnostic_msgs::DiagnosticStatus::OK,
      WARN  = diagnostic_msgs::DiagnosticStatus::WARN,
      ERROR = diagnostic_msgs::DiagnosticStatus::ERROR
    };

    diagnostic_updater::Updater diagnostic_;
    status_type                 status_;
};

} // namespace cmd_mux

#endif // CMD_MUX_DIAGNOSTICS_H
