#include "constraints/Move1617618120113Constraints.h"
/*PROTECTED REGION ID(ch1617618120113) ENABLED START*/
#include <alica_ros_turtlesim/world_model.hpp>
#include <autodiff/AutoDiff.h>
#include <engine/RunningPlan.h>
#include <engine/constraintmodul/ProblemDescriptor.h>
#include <engine/model/Task.h>
/*PROTECTED REGION END*/

namespace alica
{
// Plan:Move
/*
 * Tasks:
 * - EP:1617618274891 : FollowerTask (1617618271079)
 * - EP:1617618291624 : LeaderTask (1617618287507)
 *
 * States:
 * - AlignSquare (1617618155308)
 * - Move2Center (1617618158275)
 *
 * Vars:
 */
/**
 * RuntimeCondition - (Name): 1617618409499
 * (ConditionString):
 * Static Variables:
 * Domain Variables:
 * forall agents in Move let v = [x, y]
 *
 */
void Constraint1617618409499::getConstraint(std::shared_ptr<ProblemDescriptor> c, std::shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(cc1617618409499) ENABLED START*/
    using autodiff::TermPtr;
    autodiff::TermHolder* h = static_cast<autodiff::TermHolder*>(c->getContext());
    TermPtr constraint = h->trueConstant();
    TermPtr checkUp = h->trueConstant();
    TermPtr checkDown = h->trueConstant();
    TermPtr checkLeft = h->trueConstant();
    TermPtr checkRight = h->trueConstant();

    c->setUtility(h->constant(1));

    const int agent_num = static_cast<int>(c->getAgentVars().size());

    std::cout << "Agent No. = " << agent_num << std::endl;

    for (int i = 0; i < agent_num; ++i) {
        // get variables which is define in editor->Runtime condition->Quantifiers
        autodiff::Variable* x = static_cast<autodiff::Variable*>(c->getAgentVars()[i].getVars()[0]);
        autodiff::Variable* y = static_cast<autodiff::Variable*>(c->getAgentVars()[i].getVars()[1]);

        const alica::EntryPoint* agent_entrypoint = rp->getAssignment().getEntryPointOfAgent(c->getAgentVars()[i].getId());
        if (!agent_entrypoint) {
            // Engine doesn't guarantee consistent plan view during this function execution. A null entry
            // point means that the plan status changed between the time this function was invoked
            // and entry point was requested. Don't do anything now and ignore further constraints building.
            return;
        }

        const bool is_leader = agent_entrypoint->getTask()->getName() == "LeaderTask";

        x->editRange().intersect(0, 10);
        y->editRange().intersect(0, 10);
        autodiff::TVec<2> pos(x, y);

        constexpr float tolerance = 0.1;
        constexpr float side = 6;
        // constexpr float side_min = side - tolerance;
        // constexpr float side_max = side + tolerance;
        const autodiff::TVec<2> center(h->constant(6.0), h->constant(6.0));

        if (is_leader) // leader goes to center
        {
            constraint &= autodiff::equals(pos, center, tolerance);
        } else // follower keep distance from center and other followers
        {
            // TermPtr dist_to_center_sqr = autodiff::distanceSqr(pos, center);  // pos = (x, y) center = (h, k)   dsqr = (x-h)^2 + (y-k)^2
            // constraint &= (dist_to_center_sqr < h->constant(side_max * side_max));
            // constraint &= (dist_to_center_sqr > h->constant(side_min * side_min));

            autodiff::TermPtr x = pos.getX(), y = pos.getY();
            //std::cout << "X = " << x << " Y = " << y << std::endl;
            constexpr float uy = 9, dy = 3, lx = 3, rx = 9;
            constexpr float min_uy = uy - tolerance, min_dy = dy - tolerance, min_lx = lx - tolerance, min_rx = rx - tolerance;
            constexpr float max_uy = uy + tolerance, max_dy = dy + tolerance, max_lx = lx + tolerance, max_rx = rx + tolerance;
            checkUp &= ( (y < h->constant(max_uy)) & (y > h->constant(min_uy)) & (h->constant(min_lx) < x) & (x < h->constant(max_rx)) );    // up side
            
            checkDown &= ( (y < h->constant(max_dy)) & (y > h->constant(min_dy)) & (h->constant(min_lx) < x) & (x < h->constant(max_rx)) );  // down side
            
            checkLeft &= ( (x < h->constant(max_lx)) & (x > h->constant(min_lx)) & (y > h->constant(min_dy)) & (y < h->constant(max_uy)) );  // left side
            
            checkRight &= ( (x < h->constant(max_rx)) & (x > h->constant(min_rx)) & (y > h->constant(min_dy)) & (y < h->constant(max_uy)) ); // right side
            
            constraint &= ( ( checkUp | checkDown) | ( checkLeft | checkRight ) );

            // keep distance among followers
            for (int j = i + 1; j < agent_num; ++j) {
                // check agent is leader
                // another way to check agent is Leader
                const alica::EntryPoint* other_agent_entrypoint = rp->getAssignment().getEntryPointOfAgent(c->getAgentVars()[j].getId());
                if (!other_agent_entrypoint) {
                    // Engine doesn't guarantee consistent plan view during this function execution. A null entry
                    // point means that the plan status changed between the time this function was invoked
                    // and entry point was requested. Don't do anything now and ignore further constraints building.
                    return;
                }

                const bool is_others_leader = (other_agent_entrypoint->getId() == 1617618291624);
                if (!is_others_leader) {
                    autodiff::Variable* x_neighbour = static_cast<autodiff::Variable*>(c->getAgentVars()[j].getVars()[0]);
                    autodiff::Variable* y_neighbour = static_cast<autodiff::Variable*>(c->getAgentVars()[j].getVars()[1]);
                    const autodiff::TVec<2> pos_other(x_neighbour, y_neighbour);
                    //TermPtr dist_to_other_sqr = autodiff::distanceSqr(pos, pos_other);
                    TermPtr dist_to_other_sqr;
                    autodiff::TermPtr x_other = pos_other.getX();
                    autodiff::TermPtr y_other = pos_other.getY();

                    const autodiff::TVec<2> pos_ul(h->constant(3.0), h->constant(9.0));             // upper-left corner
                    const autodiff::TVec<2> pos_ur(h->constant(9.0), h->constant(9.0));             // upper-right corner
                    const autodiff::TVec<2> pos_dl(h->constant(3.0), h->constant(3.0));             // down-left corner
                    const autodiff::TVec<2> pos_dr(h->constant(9.0), h->constant(3.0));             // down-right corner
                    
                    if( x == x_other || y == y_other){
                        dist_to_other_sqr = autodiff::distanceSqr(pos, pos_other);
                    }
                    else if( x == h->constant(lx) && y_other == h->constant(uy) ){
                        dist_to_other_sqr = autodiff::distanceSqr(pos, pos_ul) + autodiff::distanceSqr(pos_other, pos_ul);        //    h->constant( abs(6 - y) + abs(x_other - 3));
                    }
                    // else if( x_other == h->constant(lx) && y == h->constant(uy) ){
                    //     dist_to_other_sqr = autodiff::distanceSqr(pos, pos_ur) + autodiff::distanceSqr(pos_ur, pos_dr) 
                    //     + autodiff::distanceSqr(pos_dl, pos_dr) + autodiff::distanceSqr(pos_dl, pos_other);
                    // }
                    else if( y == h->constant(uy) && x_other == h->constant(rx) ){
                        dist_to_other_sqr = autodiff::distanceSqr(pos, pos_ur) + autodiff::distanceSqr(pos_other, pos_ur);        //    h->constant( abs(9 - x) + abs(y_other - 9));
                    }
                    // else if( y_other == h->constant(uy) && x == h->constant(rx) ){
                    //     dist_to_other_sqr = autodiff::distanceSqr(pos, pos_dr) + autodiff::distanceSqr(pos_dr, pos_dl) 
                    //     + autodiff::distanceSqr(pos_dl, pos_ul) + autodiff::distanceSqr(pos_ul, pos_other);
                    // }
                    else if( x == h->constant(rx) && y_other == h->constant(dy) ){
                        dist_to_other_sqr = autodiff::distanceSqr(pos, pos_dr) + autodiff::distanceSqr(pos_other, pos_dr);        //    h->constant( abs(9 - x_other) + abs(y - 3));
                    }
                    // else if( x_other == h->constant(rx) && y == h->constant(dy) ){
                    //     dist_to_other_sqr = autodiff::distanceSqr(pos, pos_dl) + autodiff::distanceSqr(pos_dl, pos_ul) 
                    //     + autodiff::distanceSqr(pos_ul, pos_ur) + autodiff::distanceSqr(pos_ur, pos_other);
                    // }
                    else if( x_other == h->constant(lx) && y == h->constant(dy) ){
                        dist_to_other_sqr = autodiff::distanceSqr(pos, pos_dl) + autodiff::distanceSqr(pos_other, pos_dl);                      //    h->constant( abs(3 - x) + abs(y_other - 3) );
                    }
                    // else if( x == h->constant(lx) && y_other == h->constant(dy) ){
                    //     dist_to_other_sqr = autodiff::distanceSqr(pos, pos_ul) + autodiff::distanceSqr(pos_ul, pos_ur) 
                    //     + autodiff::distanceSqr(pos_ur, pos_dr) + autodiff::distanceSqr(pos_dr, pos_other);
                    // }
                    else if( x == h->constant(lx) && x_other == h->constant(rx) ){
                        dist_to_other_sqr = autodiff::distanceSqr(pos, pos_ul) + autodiff::distanceSqr(pos_ul, pos_ur) + autodiff::distanceSqr(pos_ur, pos_other);  // h->constant( abs(9 - y) + side + abs(y_other - 9) );
                    }
                    else if( y == h->constant(uy) && y_other == h->constant(dy) ){
                        dist_to_other_sqr = autodiff::distanceSqr(pos, pos_ur) + autodiff::distanceSqr(pos_ur, pos_dr) + autodiff::distanceSqr(pos_dr, pos_other);       // h->constant( abs(9 - x) + side + abs(x_other - 9) );
                    }

                   std::cout << dist_to_other_sqr->getOwner()->getTape().getValues(1) << " = val\n";

                    // calculate distance for neighbors
                   // float dis_between_followers = 2.0 * side * sin(M_PI / (float) (agent_num - 1)) - tolerance;
                    float dis_between_followers = 4.0 * (side / (float) (agent_num - 1)) - tolerance;
                    constraint &= (dist_to_other_sqr > h->constant(dis_between_followers * dis_between_followers));
                }
            }
        }
    }

    c->setConstraint(constraint);

    /*PROTECTED REGION END*/
}

// State: AlignSquare
// State: Move2Center
} // namespace alica
