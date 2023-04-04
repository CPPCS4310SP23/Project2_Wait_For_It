/*
 * Copyright (C) 2015 Niek Linnenbank
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Log.h>
#include "Kernel.h"
#include "Scheduler.h"

Scheduler::Scheduler()
{
    //DEBUG("");
    for (int i = 0; i < 5; i++)
    {
	    m_queues[i] = queue<Process*>();
    }
    m_current_priority = 0;
}

Size Scheduler::count() const
{

    //return m_queue.count();
    Size count = 0;
    for(int i = 0; i < 5; i++)
    {
	    cout += m_queues[i].size();
    }
    return count;
}

Scheduler::Result Scheduler::enqueue(Process *proc, bool ignoreState)
{
    if (proc->getState() != Process::Ready && !ignoreState)
    {
        ERROR("process ID " << proc->getID() << " not in Ready state");
        return InvalidArgument;
    }

    int priority = proc->getPriority();
    if(priority < 1 || priority >= 5)
    {
	    ERROR("Invalid priority for PID " << proc->getID());
	    return InvalidArguement;
    }

    // Add the proc to the right p queue
    m_queues[priority].push(proc);    

    //m_queue.push(proc);
    return Success;
}

Scheduler::Result Scheduler::dequeue(Process *proc, bool ignoreState)
{
    if (proc->getState() == Process::Ready && !ignoreState)
    {
        ERROR("process ID " << proc->getID() << " is in Ready state");
        return InvalidArgument;
    }

    int priority = proc->getPriority();
    if(priority < 1 || priority 5)
    {
	    ERROR("Invalid priority for PID "<< proc->getID());
	    return InvalidArguement;
    }
    queue<Process*> queue_copy = m_queues[priority];

    bool status = false;
    while(!queue_copy.empty())
    {
	    Procces* p = queue_copy.front();
	    queue_copy.pop();
	    if(p = proc)
	    {
		    found = true;
		    break;
	    }
    }

    queue<Process*> new_queue;
    if(status)
    {
	    while(!m_queues[priority].empty())
	    {
		    m_queues[priority].pop();
		    if(p != proc)
		    {
			    new_queue.push(p);
		    }
	    }
	    m_queues[priority] = new_queue;
	    return Success;
    }
    else
    {
	    FATAL("PID " << proc->getID() << " is not in the schedule.");
	    return InvalidArguement;
    }	    

    // Previous version below.
    /*Size count = m_queue.count();

    // Traverse the Queue to remove the Process
    for (Size i = 0; i < count; i++)
    {
        Process *p = m_queue.pop();

        if (p == proc)
            return Success;
        else
            m_queue.push(p);
    }

    FATAL("process ID " << proc->getID() << " is not in the schedule");
    return InvalidArgument;
    */
}

Process * Scheduler::select()
{
	for( int i = 0; i < 5; i++)
	{
		if(!m_queues[i].empty())
		{
			m_current_priority = i;
			Process *p = m_queues[i].front();
			m_queues[i].pop;
			m_queues[i].push(p);
			return p;
		}
	}
	return (Process *) NULL;

	// previous version
    /*if (m_queue.count() > 0)
    {
        Process *p = m_queue.pop();
        m_queue.push(p);

        return p;
    }

    return (Process *) NULL;
    */
}
