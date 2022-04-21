import React from 'react';

const Hero = () => {
    return (
        <div className="jumbotron text-center">
            <img src="https://github.com/bigpel66/42-cursus/blob/main/circle-05/Inception/srcs/requirements/bonus/site/tools/app/public/icon-oli.png"/>
            <form className="form-inline">
                <div className="input-group">
                    <input type="email" className="form-control" size="50" placeholder="Email Address" required />
                    <div className="input-group-btn">
                        <button type="button" className="btn btn-danger">Subscribe</button>
                    </div>
                </div>
            </form>
        </div>
    )
}

export default Hero;

