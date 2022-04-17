import React from 'react';

const Hero = () => {
    return (
        <div className="jumbotron text-center">
            <img src="https://s3.us-west-2.amazonaws.com/secure.notion-static.com/bd5f0dfd-7184-4720-ab2f-3c8a6dbe2a79/icon-oli.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20220416%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20220416T153815Z&X-Amz-Expires=86400&X-Amz-Signature=035174bd24246e94f875435ad50a223dd77f0d8bb350a2c99a2527955f2d7ae3&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22icon-oli.png%22&x-id=GetObject"/>
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

